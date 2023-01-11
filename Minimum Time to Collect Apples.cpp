class Solution {
    int solution(vector<int> adj[], vector<bool> hasApple, int src, int par) 
    {
        int t_time = 0;
        int c_time = 0;

        for(auto vals: adj[src]) {
            if(vals == par) {continue;}

            c_time = solution(adj, hasApple, vals, src);

            if(c_time || hasApple[vals]) {
                t_time+=c_time + 2;
            }
        }

        return t_time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];

        for(auto vals: edges) {
            adj[vals[0]].push_back(vals[1]);
            adj[vals[1]].push_back(vals[0]);
        }

        return solution(adj, hasApple, 0, -1);
    }
};
