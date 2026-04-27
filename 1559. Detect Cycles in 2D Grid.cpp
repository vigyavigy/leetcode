class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool detectCycleDFS(int r, int c, int prev_r, int prev_c, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (visited[r][c] == true) return true;
        visited[r][c] = true;
        for (auto& dir : directions) {
            int next_r = r + dir[0];
            int next_c = c + dir[1];
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m &&
                grid[next_r][next_c] == grid[r][c]) {
                if (next_r == prev_r && next_c == prev_c)
                    continue; // parent check
                if (detectCycleDFS(next_r, next_c, r, c, grid, visited))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && detectCycleDFS(i, j, i, j, grid, visited))
                    return true;
            }
        }
        return false;
    }
};
