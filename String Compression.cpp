class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int k = 0;
        int i = 0;
        int len = 0;
        while(i < n)
        {
            len = 0;
            char ch = chars[i];
            while(i < n and chars[i] == ch) {i++; len++;}

            chars[k] = ch;
            k++;
            if(len > 1) {
                cout<<len<<"\n";
                string s = to_string(len);
                cout<<s<<"\n";
                for(int j = 0; j < s.length(); ++j) {
                    chars[k] = s[j];
                    k++;
                }
            }
        }
        int rem = n - k;

        while(rem--)
        {
            chars.pop_back();
        }
        return chars.size();
    }
};
