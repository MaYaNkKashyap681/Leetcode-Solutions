class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low;
        if(low%2 == 0 and high %2 == 0) {
            return diff/2;
        }
        int p = diff / 2;
        return p + 1;
    }
};
