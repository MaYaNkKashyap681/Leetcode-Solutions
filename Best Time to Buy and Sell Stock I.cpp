class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int bought = prices[0];
        for(int i = 1; i < n; ++i) {
            if(bought <= prices[i])
                ans = max(abs(prices[i] - bought), ans);
            else
                bought = prices[i];
        }
        return ans;
    }
};
