class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col_len = strs[0].length();
        int row_len = strs.size();
        int ans = 0;
        for(int i = 0; i < col_len; ++i) 
        {
            for(int j = 0; j < row_len - 1; ++j) {
                if(strs[j][i] > strs[j + 1][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
