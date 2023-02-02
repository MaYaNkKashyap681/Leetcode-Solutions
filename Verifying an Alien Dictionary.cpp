/*Solution 1*/

unordered_map<char, int> mp;
    bool cmp(string a, string b)
    {
         int n = min(a.length(), b.length());

         for(int i = 0; i < n; ++i) {
             if(mp[a[i]] < mp[b[i]]) {
                 return true;
             }
             else if(mp[a[i]] > mp[b[i]]) {
                 return false;
             }
         }

         if(a.length() > b.length()) {
             return false;
         }
         return true;
    }

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); ++i) {
            mp[order[i]] = i;
        }

        vector<string> temp = words;

        sort(temp.begin(), temp.end(), cmp);

        return words == temp;
    }
};

/*Solution 2*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;

        for(int i = 0; i < order.length(); ++i) {
            mp[order[i]] = i;
        }

        int len = words.size();

        for(int i = 0; i < len - 1; ++i) 
        {
            string a = words[i];
            string b = words[i + 1];
            for(int j = 0; j < words[i].length(); ++j)
            {
                if(j >= words[i + 1].length()) {return false;}

                if(a[j] != b[j]) {
                    if(mp[a[j]] > mp[b[j]]) {
                        return false;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return true;
    }
};
