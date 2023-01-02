class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int lc = 0;
        int uc = 0;

        for(auto vals: word) {
            bool isUc = isupper(vals);

            if(isUc) {
                uc++;
            }
            else {
                lc++;
            }
        }

        if(uc == n  or lc == n or (uc == 1 and isupper(word[0]))) {
            return true;
        }

        return false;
    }
};
