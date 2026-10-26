class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (grid[r][c] > 0) {
                    ans += dfs(r,c,grid) % k == 0 ? 1 : 0;
                }
            }
        }
        return ans;
    }

    long long dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0|| r >= m || c < 0 || c >= n || grid[r][c] <= 0) {
            return 0;
        }
        long long sum = grid[r][c];
        grid[r][c] = -1;
        sum += dfs(r-1, c, grid);
        sum += dfs(r+1, c, grid);
        sum += dfs(r, c-1, grid);
        sum += dfs(r, c+1, grid);
        return sum;
    }
};