class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        

        vector<int> ans;
        int l1 = num.size();
        int cur = k;
        int i = l1 - 1;

        while(i >= 0 || cur > 0) {
            if(i >= 0) {
                cur+=num[i];
            }

            ans.push_back(cur%10);
            cur/=10;
            i--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
