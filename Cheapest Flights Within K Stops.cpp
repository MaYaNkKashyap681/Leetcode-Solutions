class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto vals: flights) {
            adj[vals[0]].push_back({vals[1], vals[2]});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;

        dist[src] = 0;
        
        q.push({0,{0, src}});

        while(!q.empty())
        {
           int a = q.front().first;
           int b = q.front().second.first;
           int c = q.front().second.second;
           q.pop();

           if(a > k) {continue;}
           for(auto vals: adj[c]) {
               if(b + vals.second <= dist[vals.first] and a <= k) {
                   dist[vals.first] = b + vals.second;
                   q.push({a + 1, {dist[vals.first], vals.first}});
               }
           }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
