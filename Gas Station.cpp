class Solution {
    int sum(vector<int> v)
    {
        int sum = 0;
        for(auto vals: v) {
            sum+=vals;
        }

        return sum;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int a = sum(gas);
        int b = sum(cost);
        int n = gas.size();
        if(a < b) {return -1;}

        int ans = 0;
        int temp = 0;
        for(int i = 0; i < n; ++i) {
            temp+=(gas[i] - cost[i]);
            if(temp < 0) {
            temp = 0;
            ans = i + 1;
            }
        }

        return ans;
    }
};
