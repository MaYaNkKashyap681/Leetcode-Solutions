class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<vector<int>> s_tasks;

        for(int i = 0; i < n; ++i) {
            s_tasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(s_tasks.begin(), s_tasks.end());


        long long current_time = 0;
        vector<int> ans;
        long long t_idx = 0;

        while(t_idx < n or !pq.empty()) {
            if (pq.empty() && current_time < s_tasks[t_idx][0]) {
                current_time = s_tasks[t_idx][0];
            }

            while(t_idx < n and s_tasks[t_idx][0] <= current_time) {
                pq.push({s_tasks[t_idx][1], s_tasks[t_idx][2]});
                t_idx++;
            }

            ans.push_back(pq.top().second);
            current_time+=pq.top().first;
            pq.pop();

        }
        return ans;
    }
};
