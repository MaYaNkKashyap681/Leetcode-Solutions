class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            int b = target - a;

            if(mp.find(b) != mp.end()) {
                return {i, mp[b]};
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};
