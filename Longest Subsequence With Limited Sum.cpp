class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());

        vector<int> p_sum(n + 1, 0);
        for(int i = 1; i <=n; ++i) {
            p_sum[i] = p_sum[i - 1] + nums[i - 1];
        }

        for(int i = 0; i <m ; ++i) {
            int len = 0;
            for(int j = 1; j <=n; ++j) {
                if(p_sum[j] <= queries[i]) {
                    len++;
                }
                else {
                    break;
                }
            }
            ans.push_back(len);
        }
           return ans;
    }
};
