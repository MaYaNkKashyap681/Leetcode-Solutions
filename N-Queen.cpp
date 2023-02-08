class Solution {
   bool isSafe(vector<vector<char>> &board, int n, int row, int col)
{
    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    int i = row, j = col;
    while (i >= 0 && j >= 0)
        if (board[i--][j--] == 'Q')
            return false;
    i = row, j = col;
    while (i >= 0 && j < board.size())
        if (board[i--][j++] == 'Q')
            return false;
    return true;
}

void solve(vector<vector<char>> &board, int n, int idx, vector<vector<string>> &ans)
{
    if(idx == n) {
      
        vector<string> temp;
        string strs;
        for(int x = 0; x < n; ++x) {
            strs.clear();
            for(int y = 0; y < n; ++y) {
                strs.push_back(board[x][y]);
            }
            temp.push_back(strs);
        }

        ans.push_back(temp);
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(isSafe(board, n, idx, i)) {
            board[idx][i] = 'Q';
            solve(board, n, idx + 1, ans);
            board[idx][i] = '.';
        }
    }
    return;
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(board, n, 0, ans);    


        return ans;
    }
};
