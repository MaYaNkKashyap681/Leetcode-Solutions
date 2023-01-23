class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n + 1, 0);
        vector<int> outdeg(n + 1, 0);

        for(auto vals: trust) {
            indeg[vals[1]]++;
            outdeg[vals[0]]++;
        }

        for(int i = 1; i <= n; ++i) {
            if(indeg[i] == n - 1 and outdeg[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};
