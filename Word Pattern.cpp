class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, vector<int>> mp;

        for(int i = 0; i < pattern.length(); ++i) {
            mp[pattern[i]].push_back(i);
        }

        vector<string> words;
        string temp;
        for(auto vals: s) {
            if(vals == ' ') {
                words.push_back(temp);
                temp.clear();
            }
            else {
                temp.push_back(vals);
            }
        }
        words.push_back(temp);

        if(pattern.length() != words.size()) {return false;}
        set<string> st;

        for(auto it = mp.begin(); it != mp.end(); ++it) {
            vector<int> x = it->second;

            if(st.find(words[x[0]]) != st.end()) {return false;}
            for(int i = 0; i < x.size() - 1; ++i) {
                if(words[x[i]] != words[x[i + 1]]) {
                    return false;
                }
            } 

            st.insert(words[x[0]]);
        }

        return true;
    }
};
