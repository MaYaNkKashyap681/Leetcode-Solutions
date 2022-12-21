class Solution {
    bool isBipartite(int node, vector<int> adj[], vector<int> &colors)
    {
       

        queue<int> q;
        colors[node] = 1;
        q.push(node);

        while(!q.empty())
        {
            int x = q.front();
            int col = colors[x];
            q.pop();

            for(auto vals: adj[x]) 
            {
                if(colors[vals] == -1) {
                    colors[vals] = 1 - col;
                    q.push(vals);
                }
                else if(colors[vals] == col) {
                    return false;
                }
            }
        }
         return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n + 1];
        for(auto vals: dislikes) {
            adj[vals[0]].push_back(vals[1]);
            adj[vals[1]].push_back(vals[0]);
        }

        vector<int> colors(n + 1, -1);

        for(int i = 1; i <= n; ++i) {
            if(colors[i] == -1) {
                if(isBipartite(i, adj, colors) == false) {
                    return false;
                }
            }
        }

        return true;
    }
}; 
