class Solution {
    map<int,int> mp;
    
void solution(vector<int> nums, vector<vector<int>> &ans, vector<int> &temp) 
    {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        } 
    
        for(int i = 0;i<nums.size();++i){
           if(mp[nums[i]] == 0){
               temp.push_back(nums[i]);
               mp[nums[i]] = 1;
               solution(nums, ans, temp);
               temp.pop_back();
               mp[nums[i]] = 0;
           }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
   
    vector<vector<int>> ans;
    vector<int> temp;
    solution(nums, ans, temp);
    return ans;
    }
};
