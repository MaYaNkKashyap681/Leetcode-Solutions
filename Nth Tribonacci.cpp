class Solution {
    int solution(int n, vector<int> &dp)
    {
        if(n == 0) {return 0;}
        else if(n == 1 or n == 2) {return 1;}
        if(dp[n] != -1) {return dp[n];}

        return dp[n] = solution(n - 1, dp) + solution(n - 2, dp) + solution(n - 3, dp);
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n + 10, -1);
        return solution(n, dp);
    }
};
