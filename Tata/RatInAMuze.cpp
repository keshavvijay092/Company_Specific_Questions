class Solution {
public:
    void solve(vector<vector<int>> mat, int n, int x, int y, vector<string>& ans, string path, vector<vector<int>>& visited) {
        // Base case: if the current cell is the bottom-right corner
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        
        // Possible movements: Down, Left, Right, Up
        vector<int> X = {1, 0, 0, -1};
        vector<int> Y = {0, -1, 1, 0};
        vector<char> direction = {'D', 'L', 'R', 'U'};
        
        for (int i = 0; i < 4; i++) {
            int newX = x + X[i];
            int newY = y + Y[i];
            
            // Check if the new position is valid and not visited
            if (newX >= 0 && newY >= 0 && newX < n && newY < n && mat[newX][newY] == 1 && !visited[newX][newY]) {
                // Mark the cell as visited
                visited[x][y] = 1;
                // Recur for the next cell
                solve(mat, n, newX, newY, ans, path + direction[i], visited);
                // Backtrack: Unmark the current cell
                visited[x][y] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<string> ans;
        string path = "";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        // Start solving from (0, 0) if it's a valid start point
        if (mat[0][0] == 1) {
            solve(mat, n, 0, 0, ans, path, visited);
        }
        
        return ans;
    }
};



