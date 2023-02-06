class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       int i = 0;
       int j = n;
       int len = n + n;
       vector<int> ans;
       while(j < len) 
       {
           ans.push_back(nums[i]);
           ans.push_back(nums[j]);
           i++;
           j++;
       }   
       return ans;
    }
};
