class Solution {
    int len;
public:

    void solution(string s, int idx, vector<string> &ans) {
        if(idx == len) {
            ans.push_back(s);
            return;
        }

        if(isalpha(s[idx])) {
            if(islower(s[idx])) {
            s[idx] = toupper(s[idx]);
            solution(s, idx + 1, ans);
             s[idx] = tolower(s[idx]);
            }

            else if(isupper(s[idx])) {
            s[idx] = tolower(s[idx]);
            solution(s, idx + 1, ans);
             s[idx] = toupper(s[idx]);
            }
        }
        solution(s, idx + 1, ans);
    }
    vector<string> letterCasePermutation(string s) {
        len = s.size();
        vector<string> ans;
        solution(s, 0, ans);
        return ans;
    }
};
