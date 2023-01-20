class Solution {
    int n;
    void solution(vector<int> nums, vector<int> temp, set<vector<int>> &ans , int idx)
    {
        if(idx == n) {ans.insert(temp); return;}

        solution(nums, temp, ans, idx + 1);

        if(temp.size() == 0 or temp[temp.size() - 1] <= nums[idx]) {
            temp.push_back(nums[idx]);
            solution(nums, temp, ans, idx + 1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        set<vector<int>> ans;
        vector<int> temp;
        vector<vector<int>> ans2;
        solution(nums, temp, ans, 0);
          for(auto it = ans.begin(); it != ans.end(); ++it) {
            if(it->size() > 1) {
                ans2.push_back(*it);
            }
        }
        return ans2;
    }
};
