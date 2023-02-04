public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp;
        for(auto vals: s1) {
            mp[vals]++;
        }

        int i = 0;
        int j = 0;
        map<char, int> mp2;
        int n = s2.length();
        int k = s1.length();

        if(k > n) {return false;}
        while(j < n)
        {
           mp2[s2[j]]++;

           if((j - i + 1) < k) {
               j++;
           }
           else if((j - i + 1) == k){
              if(mp == mp2) {
                  return true;
              }
              mp2[s2[i]]--;
              if(!mp2[s2[i]]) {
                  mp2.erase(s2[i]);
              } 
              i++;
              j++;
           }
        }
        return false;
    }
};
