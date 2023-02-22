class Solution {
    bool isValid(vector<int> &weights, int days, int maxs) 
    {
        int d = 1;
        int temp = 0;
        for(auto vals: weights) {
            if(vals > maxs) {
                return false;
            }
            temp+=vals;
            if(temp > maxs) {
                d++;
                temp = vals;
            }
        }

        return d <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        

        int n = weights.size();
        int i = 0;
        int j = 0;
        for(auto vals: weights) {
            j+=vals;
        }
        int mid;

        while(i <= j) 
        {
            mid = i + (j - i) / 2;

            if(isValid(weights, days, mid)) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return i;
    }
};
