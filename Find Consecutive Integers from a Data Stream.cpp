class DataStream {
    map<int, int> mp;
    int occ = 0;
    int val = 0;
public:
    DataStream(int value, int k) {
        mp[value]=0;
        occ = k;
        val = value; 
    }
    
    bool consec(int num) {
        if(num == val) {
            mp[val]++;
        }
        else {
        mp[val] = 0;
        }

        if(mp[val] >= occ) {return true;}
        return false;

    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
