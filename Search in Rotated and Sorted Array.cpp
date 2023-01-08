class Solution {

    int binary_search(vector<int> &nums, int a, int b, int target){
        int n = nums.size();
        int l = a;
        int h = b;
        int mid;
        while(l<=h)
        {
            mid = l + (h - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                h = mid - 1 ;
            }
            else {
                l = mid + 1;
            }
        }

        return -1;
    }

    int pivotFinder(vector<int> v) 
    {
        int n = v.size();
        int l = 0;
        int h = n - 1;
        int mid = 0;
        while(l < h)
        {
            mid = l + (h - l) / 2;

            if(v[mid] >= v[0]) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        return h;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = pivotFinder(nums);
        cout<<pivot<<"\n";
        if(nums[pivot] <= target and target <= nums[n - 1]) {
            return binary_search(nums, pivot, n - 1, target);
        }

        return binary_search(nums, 0, pivot - 1, target);
    }
};
