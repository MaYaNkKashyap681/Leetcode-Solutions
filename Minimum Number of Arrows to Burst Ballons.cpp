class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());

        int ans = 1;
        int a = points[0][0];
        int b = points[0][1];
        int i = 1;
      
        while(i < n) 
        {
           if(points[i][0] <= b) {
               b = min(b, points[i][1]);
               i++;
           }
           else {
               ans++;
               a = points[i][0];
               b = points[i][1];
            }
        }
        return ans;
    }
};
