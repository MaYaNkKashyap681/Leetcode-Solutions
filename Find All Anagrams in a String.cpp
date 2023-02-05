class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int k = p.length();

        vector<int> ans;
        map<char, int> mp;
        map<char, int> temp;
        for(auto vals: p) {
            mp[vals]++;
        }
        int i = 0;
        int j = 0;

        while(j < n)
        {
            temp[s[j]]++;
            if((j - i + 1) < k) {
                j++;
            }
            else if((j - i + 1) == k) 
            {
                if(mp == temp) {
                    ans.push_back(i);
                }

                temp[s[i]]--;
                if(!temp[s[i]]) {
                    temp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
