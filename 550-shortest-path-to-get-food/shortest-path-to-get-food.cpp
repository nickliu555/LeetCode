class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> bfsQueue;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == '*') {
                    bfsQueue.push({r, c});
                    visited[r][c] = true;
                    break;
                }
            }
        }
        
        int ans = 0;
        vector<int> dirs = {1,0,-1,0,1};
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            for (int i=0; i<size; ++i) {
                int r = bfsQueue.front().first;
                int c = bfsQueue.front().second;
                bfsQueue.pop();

                if (grid[r][c] == '#') return ans;

                for (int i=0; i<4; ++i) {
                    int newR = r + dirs[i];
                    int newC = c + dirs[i+1];
                    if (newR < 0 || newR >= m || newC < 0 || newC >= n || grid[newR][newC] == 'X' || visited[newR][newC]) continue;
                    bfsQueue.push({newR, newC});
                    visited[newR][newC] = true;
                }
            }
            ++ans;
        }
        return -1;
    }
};