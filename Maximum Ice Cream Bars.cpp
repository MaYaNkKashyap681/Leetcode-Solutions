class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto vals: costs) 
        {
            pq.push(vals);
        }

        int ans = 0;
        while(!pq.empty() and coins > 0 and pq.top() <= coins) 
        {
            int x = pq.top();
            pq.pop();
            coins-=x;
            ans++;
        }

        return ans;
    }
};
