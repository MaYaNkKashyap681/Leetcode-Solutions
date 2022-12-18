 vector<int> dailyTemperatures(vector<int>& temps) {
      int n = temps.size();

      stack<pair<int, int>> st;

      vector<int> ans;

      for(int i = n - 1; i >= 0; --i)
      {
          if(st.empty())
          {
              st.push({temps[i], i});
              ans.push_back(0);
          }
          else {
              while(!st.empty() and st.top().first <= temps[i]) {
                  st.pop();
              }

              if(st.empty()) {
                  ans.push_back(0);
              }
              else {
                  ans.push_back(abs(st.top().second - i));
              }

              st.push({temps[i], i});
          }
      }
       reverse(ans.begin(), ans.end());
      return ans;
    }
