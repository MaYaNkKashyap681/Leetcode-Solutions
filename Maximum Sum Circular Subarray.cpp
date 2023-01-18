class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     int arr_sum = 0;
     int max_s_sum = INT_MIN;
     int min_s_sum = INT_MAX;
     int cur_max = 0;
     int cur_min = 0;

     for(int i = 0; i < nums.size(); ++i) {
         arr_sum+=nums[i];

         cur_max+=nums[i];
         cur_min+=nums[i];
         max_s_sum = max(max_s_sum, cur_max);
         min_s_sum = min(min_s_sum, cur_min);
         if(cur_max < 0) {
             cur_max = 0;
         }
         if(cur_min > 0) {
             cur_min = 0;
         }
     }  

     if(arr_sum == min_s_sum) {
         return max_s_sum;
     } 

     return max(max_s_sum, (arr_sum - min_s_sum));
    }
};
