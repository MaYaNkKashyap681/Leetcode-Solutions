class Solution {
    int ans = 0;
    int m;
    int n;
    pair<int, int> sp;
    pair<int, int> ep;
    int dir1[4] = {0, -1, 0, 1};
    int dir2[4] = {1, 0, -1, 0};
public:
    
    void uq_paths(int i, int j, vector<vector<int>> grid, int &gd_sum)
    {
        if(i == ep.first and j == ep.second and gd_sum == 3)
        {
            ans++;
            return;
        }
        
        if(i == ep.first and j == ep.second and gd_sum != 3)
        {
            return;
        }
        
        for(int k = 0; k < 4; ++k)
        {
            int new_i = i + dir1[k];
            int new_j = j + dir2[k];
            
            if(new_i >= 0 and new_j >= 0 and new_i < m and new_j < n and grid[i][j] != -1)
            {
                gd_sum-=3;
                grid[i][j] = -1;
                uq_paths(new_i, new_j, grid, gd_sum);
                grid[i][j] = 0;
                gd_sum+=3;
            }
        }
        
        return;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        int gd_sum = 0;
        
        for(int i = 0; i<m; ++i) {
            for(int j = 0;j<n; ++j) {
                if(grid[i][j] == 1)
                {
                    sp.first = i;
                    sp.second = j;
                }
                
                if(grid[i][j] == 2) 
                {
                    ep.first = i;
                    ep.second = j;
                }
                
                if(grid[i][j] != -1)
                {
                    gd_sum+=3;
                }
            }
        }
        
        uq_paths(sp.first, sp.second, grid, gd_sum);
        return ans;
    }
};
