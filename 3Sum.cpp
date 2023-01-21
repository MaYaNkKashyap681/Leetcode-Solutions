class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp(3);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++i) 
        {
            int target = 0 - nums[i];
            int l = i + 1;
            int h = nums.size() - 1;
            
            while(l < h)
            {
                int sum = nums[l] + nums[h];
                
                if(sum > target) 
                {
                    h--;
                }
                else if(sum < target) 
                {
                    l++;
                }
                else 
                {
                    temp[0] = nums[i];
                    temp[1] = nums[l];
                    temp[2] = nums[h];
                    
                    ans.push_back(temp);
                    
                    while(l < h and nums[l] == temp[1]) l++;
                    while(l < h and nums[h] == temp[2]) h--;
                }
            }
            
            while(i + 1 < n and nums[i + 1] == nums[i]) i++;
          }
        
        return ans;
    }
};
