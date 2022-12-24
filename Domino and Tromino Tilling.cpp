class Solution {
public:
    int numTilings(int n) {
        if(n == 0) {return 1;}
        if(n == 1) {return 1;}
        else if(n == 2) {return 2;}
        const int mod = 1000000007;
        vector<int> dp(n + 10, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; ++i) {
            dp[i] = ((2*dp[i - 1])%mod + dp[i - 3])%mod;
        }

        return dp[n] % mod;
        }
};

/*Space Optimized*/

class Solution {
public:
    int numTilings(int n) {

        int a = 1;
        int b = 1;
        int c = 2;
        const int mod = 1000000007;
        if(n == 1 or n == 2) {return n;}
        int x;
        for(int i = 3; i <= n; ++i) {
            x = ((2*c)%mod + a)%mod;
            a = b;
            b = c;
            c = x;
        }
        return x;
    }
};

