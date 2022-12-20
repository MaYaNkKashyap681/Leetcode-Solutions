class Solution {
    void  dfs(int src, vector<vector<int>> rooms, set<int> &st)
    {
        st.insert(src);

        for(int i = 0; i < rooms[src].size(); ++i) {
            if(st.find(rooms[src][i]) == st.end()) {
                dfs(rooms[src][i], rooms, st);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> st;
        
        dfs(0,rooms, st);  

        return st.size() == rooms.size();
    }
};
