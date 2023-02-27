class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            int a = nums[i];
            long long int tar1 = target - nums[i];
            for(int j = i + 1; j < n; ++j) {
                int b = nums[j];
                long long int tar2 = tar1 - nums[j];
                int k = j + 1;
                int m = n - 1;
                while(k < m) 
                {
                    int x = nums[k];
                    int y = nums[m];
                    long long int t = x + y;
                    if(t == tar2) {
                        ans.push_back({a, b, x, y});

                        while(k < m and nums[k] == x) {k++;}
                        while(k < m and nums[m] == y) {m--;}
                    }
                    else if(t > tar2) {
                        m--;
                    }
                    else {
                        k++;
                    }
                }

                while(j < n and nums[j] == b) {j++;}
                j--;
            }
            while(i < n and nums[i] == a) {i++;}
            i--;
        }

        return ans;
    }
};
