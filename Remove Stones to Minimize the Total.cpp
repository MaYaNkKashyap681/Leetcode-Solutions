class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int> pq;
      for(auto vals: piles) {
          pq.push(vals);
      }   

      int ans = 0;

      while(!pq.empty() and k--) 
      {
          int x = pq.top();
          pq.pop();
          int y = x / 2;
          y = x - y;
          if(y != 0) {
              pq.push(y);
          }
      }
     
      while(!pq.empty()) 
      {
          ans+=pq.top();
          pq.pop();
      }

      return ans;
    }
};
