class Solution {
public:
    bool IsSafe(int row, int col, vector<string>& board, int n) {
        // Check this row on the left side
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') return false;
        }

        // Check upper diagonal on the left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check lower diagonal on the left side
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int col, int n, vector<vector<string>>& ans, vector<string>& board) {
        // Base case: If all queens are placed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Consider this column and try placing this queen in all rows one by one
        for (int i = 0; i < n; i++) {
            if (IsSafe(i, col, board, n)) {
                board[i][col] = 'Q';  // Place this queen on board[i][col]

                solve(col + 1, n, ans, board);  // Recur to place the rest of the queens

                board[i][col] = '.';  // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  // Initialize board
        solve(0, n, ans, board);  // Start from the first column
        return ans;
    }
};