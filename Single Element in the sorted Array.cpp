class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int mid;
        if(n == 1) {
            return nums[0];
        }

        if(nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        while(i <= j)
        {
            mid = j - (j - i)/2;
            if((nums[mid] != nums[mid - 1]) and (nums[mid] != nums[mid + 1])) {
                return nums[mid];
            } 
            else if(((mid%2 == 0) and nums[mid] == nums[mid + 1]) or ((mid % 2 == 1) and nums[mid] == nums[mid - 1])) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return nums[i];
    }
};
