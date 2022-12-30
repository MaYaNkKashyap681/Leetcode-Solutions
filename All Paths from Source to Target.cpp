class Solution {
    void solution(int src, int target, vector<int> adj[], vector<vector<int>> &ans, vector<int> &temp, vector<int> &vis)
    {
        vis[src] = 1;
        temp.push_back(src);

        if(src == target) {
            ans.push_back(temp);
            return;
        }

        for(auto vals: adj[src]) {
            if(!vis[vals]) {
                solution(vals, target, adj, ans, temp, vis);
                vis[vals] = 0;
                temp.pop_back();
            }
        }

        return;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;

        vector<int> adj[n + 1];

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < graph[i].size(); ++j) {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            cout<<i<<"-> ";
            for(auto vals: adj[i]) {
                cout<<vals<<" ";
            }
            cout<<"\n";
        }
        vector<int> vis(n + 1, 0);
        solution(0, n - 1, adj, ans, temp, vis);
        return ans;
    }
};
