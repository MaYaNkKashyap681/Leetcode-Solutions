class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int ,int> mp;

        for(auto vals: tasks) {
            mp[vals]++;
        }

        int rounds = 0;

        for(auto it = mp.begin(); it != mp.end(); ++it) {
            int x = it->second;
            if(x == 1) {
                return -1;
            }
            if(x % 3 == 0) {rounds+=x / 3;}
            else {
               int a = x / 3;
               x = x - a*3;
               rounds = rounds + a + (x % 2 == 0 ? x/2 : x/2 + 1);
            }
        }

        return rounds;
    }
};
