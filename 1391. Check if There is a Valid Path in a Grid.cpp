class Solution {
public:
    int n, m;
    unordered_map<int, vector<vector<int>>> directions = {
        {1, {{0, -1}, {0, 1}}},  {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, {6, {{-1, 0}, {0, 1}}}};
    bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i == n - 1 && j == m - 1) return true;
        visited[i][j] = true;
        for (auto& dir : directions[grid[i][j]]) {
            int next_i = i + dir[0];
            int next_j = j + dir[1];
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m ||
                visited[next_i][next_j])
                continue;
            // IMPORTANT to check whether we can come back to previous position
            for (auto& backdir : directions[grid[next_i][next_j]]) {
                if (next_i + backdir[0] == i && next_j + backdir[1] == j) {
                    if (dfs(grid, next_i, next_j, visited))
                        return true;
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return dfs(grid, 0, 0, visited);
    }
};
