class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 1;

        int i = 0;
        int j = 0;
        map<int, int> mp;
        for(j = 0; j < n; ++j) {
            mp[fruits[j]]++;
            while(mp.size() > 2) {
                mp[fruits[i]]--;
                if(!mp[fruits[i]]) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans = max((j - i + 1), ans);
        }
        return ans;
    }
};
