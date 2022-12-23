class Solution {
    int n;
    int solution(vector<int> prices, int idx, int buy, vector<vector<long>> &dp) 
    {
       if(idx >= n) {
           return 0;
       }

       if(dp[idx][buy] != -1) {return dp[idx][buy];}

        long profit;
        if(buy) {
            profit = max(-prices[idx] + solution(prices, idx + 1, 0, dp),
            0 + solution(prices, idx + 1, 1, dp));
        }
        else {
            profit = max(prices[idx] + solution(prices, idx + 2, 1, dp),
            0 + solution(prices, idx + 1, 0, dp));
        }

        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
          n = prices.size();
          vector<vector<long>> dp(n + 10, vector<long>(2, -1));
          return solution(prices, 0, 1, dp);
       
    }
};
