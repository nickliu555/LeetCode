class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (grid[r][c] == 0) {
                    ans += dfs(r, c, grid);
                }
            }
        }
        return ans;
    }

    bool dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[r][c] == 1 || grid[r][c] == -1) {
            return true;
        }
        if (r == 0 || r == m-1 || c == 0 || c == n-1) {
            return false;
        }

        // grid[r][c] = -1 means its land that has been visited already
        grid[r][c] = -1;
        bool up = dfs(r-1, c, grid);
        bool down = dfs(r+1, c, grid);
        bool left = dfs(r, c-1, grid);
        bool right = dfs(r, c+1, grid);
        
        return up && down && left && right;
    }
};