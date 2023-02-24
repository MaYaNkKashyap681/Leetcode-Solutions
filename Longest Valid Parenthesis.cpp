class Solution {
public:
    int longestValidParentheses(string s) {
        int o = 0;
        int c = 0;
        int n = s.length();

        int res1 = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') o++;
            if(s[i] == ')') c++;
            if(c > o){o = 0; c = 0;}
            if(o == c) {
                res1 = max(res1, 2*o);
            }
        }
        o = 0;
        c = 0;
        int res2 = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '(') o++;
            if(s[i] == ')') c++;
            if(o > c){o = 0; c = 0;}
            if(o == c) {
                res2 = max(res2, 2*o);
            }
        }   

        return max(res1, res2);
    }
};
