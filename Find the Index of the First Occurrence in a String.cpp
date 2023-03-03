class Solution {
int is_match(vector<int> pi, string pattern, string text)
{   
    int m = pattern.length();
    int n = text.length();
    int i = 0;
    int j = 0;

    while(i < n)
    {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        else if(text[i] != pattern[j] and j > 0) {
            j = pi[j - 1];
        }
        else {
            j = 0;
            i++;
        }

        if(j == m) {return i - j;}
    }
    return -1;
}

public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> pi(m, -1);

        int i = 1;
        int j = 0;

        pi[0] = 0;

        while(i < m)
        {
            if(needle[i] == needle[j]) {
                pi[i] = j + 1;
                i++;
                j++;
            }
            else if(needle[i] != needle[j] and j > 0) {
                j = pi[j - 1];
            }
            else if(needle[i] != needle[j] and j == 0) {
                pi[i] = 0;
                i++;
            }
        }

       return is_match(pi, needle, haystack);
    }
};
