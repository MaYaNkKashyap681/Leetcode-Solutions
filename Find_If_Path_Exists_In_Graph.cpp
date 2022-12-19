class Solution {
   bool dfs(int node,vector<int> adj[],vector<bool> &vis, int dest){

        if(node == dest) {return true;} 
    
       vis[node]=1;

       for(int j=0;j<adj[node].size();++j){
        if(!vis[adj[node][j]]){
          if(dfs(adj[node][j],adj,vis, dest)) {
              return true;
          }
        }
    }
    return false;
}
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];

        for(auto vals: edges) {
            adj[vals[0]].push_back(vals[1]);
            adj[vals[1]].push_back(vals[0]);
        }

        vector<bool> vis(n, false);

        return dfs(source, adj, vis, destination);
    }
};
