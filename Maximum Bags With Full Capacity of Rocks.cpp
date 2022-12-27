class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addRocks) {
       int n = rocks.size();
       priority_queue<int, vector<int>, greater<int>> pq;
       
       for(int i = 0; i < n ;++i) {
           pq.push(capacity[i] - rocks[i]);
       }
      
       int ans = 0;
       while(!pq.empty()) 
       {
           int x = pq.top();
           if(x <= addRocks) {
               addRocks-=x;
               pq.pop();
               ans++;
           }
           else {
               break;
           }
       }
       return ans;
    }
};
