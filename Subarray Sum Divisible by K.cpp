class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       
        
      int n = nums.size();
      int mods[k];
      for(int i = 0;i<k;++i){
        mods[i] = 0;
      }

      int sum = 0;
      int cnt = 0;
      mods[0]++;
      for(int i = 0;i<n;++i){
        sum+=nums[i];
        int rem = sum%k;
        if(rem<0){
            rem+=k;
        }
        if(mods[rem]==0){
            mods[rem]++;
        }
        else{
            cnt+=mods[rem];
            mods[rem]++;
        }
      }
        
        return cnt;
    }
};
