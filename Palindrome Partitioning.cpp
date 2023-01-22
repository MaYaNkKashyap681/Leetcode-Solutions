class Solution {
public:
    bool is_pallindrome(string s, int start, int end)
    {
        //Replacement of the for loop
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
    
    void pallindrome_partition(string s, int idx,  vector<string> temp, vector<vector<string>> &ans)
    {
        if(idx == s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.size(); ++i)
        {
            if(is_pallindrome(s, idx, i))
            {
                string str = s.substr(idx, i - idx + 1);
                
                /*
                Let say string is abcdefgh
                idx = 1
                i = 1
                
                i - idx + 1 = 1 - 1 + 1 = 1
                substr -> b
                i - idx + 1 = 2 - 1 + 1 = 2
                substr -> bc
                */
                temp.push_back(str);
                pallindrome_partition(s, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        pallindrome_partition(s, 0, temp, ans);
        return ans;
    }
};
