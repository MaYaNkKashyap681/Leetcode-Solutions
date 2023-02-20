class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(binary_search(nums.begin(), nums.end(), target)) {
            return lb - 1;
        } 
        return lb;
    }
};
