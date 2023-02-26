class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        priority_queue<int> maxh;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minh;

        for(int i = 0; i < n; ++i) {
            minh.push({capital[i], profits[i]});
        }

        for(int i = 0; i < k; ++i) {
            while(!minh.empty() and minh.top().first <= w) {
                maxh.push(minh.top().second);
                minh.pop();

            }

            if(maxh.empty()) {
                break;
            }
            w+=maxh.top();
            maxh.pop();
        }
        return w;
    }
};
