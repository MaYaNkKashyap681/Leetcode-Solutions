class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    vector<bool> v(3000, 0);

    for(auto vals: arr) {
        v[vals] = true;
    }

    int i = 1;
    while(true) 
    {
      if(!v[i]) {
          k--;
      }
      if(!k) {break;}
      i++;
    }
    
    return i;
    }
};
