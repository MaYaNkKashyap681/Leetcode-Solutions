class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int r = 0;
      for(int i = 0; i < n; ++i) {
          if(r < i) {return false;}

          r = max(i + nums[i], r);
      }   

      return true;
    }
};
