class Solution {

    void distanceCalculator(int src, vector<int> adj[], vector<int> &dist)
    {
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(auto vals: adj[x]) {
                if(dist[x] + 1 <= dist[vals]) {
                    dist[vals] = 1 + dist[x];
                    q.push(vals);
                }
            }
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      
        int n = edges.size();
        vector<int> adj[n];
        //creating adjacency list
        for(int i = 0; i < n; ++i) {
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        vector<int> dist1(n, 1e9);
        vector<int> dist2(n, 1e9);

        distanceCalculator(node1, adj, dist1);
        distanceCalculator(node2, adj, dist2);
        int ansnode = -1;
        int mins = INT_MAX;
        for(int i = 0; i < n; ++i) {
            if(dist1[i] != 1e9 and dist2[i] != 1e9) {
                int x = max(dist1[i], dist2[i]);
                if(mins > x) {
                    mins = x;
                    ansnode = i;
                }
            }
        }

        return ansnode;
    }
};
