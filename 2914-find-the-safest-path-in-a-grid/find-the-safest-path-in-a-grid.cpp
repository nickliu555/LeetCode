class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> bfsQueue;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == 1) {
                    bfsQueue.push({r, c});
                    grid[r][c] = 0;
                } else {
                    grid[r][c] = -1;
                }
            }
        }

        int dist = 1;
        vector<int> dirs = {1,0,-1,0,1};
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            for (int i=0; i<size; ++i) {
                int r = bfsQueue.front().first;
                int c = bfsQueue.front().second;
                bfsQueue.pop();

                for (int i=0; i<4; ++i) {
                    int rr = r + dirs[i];
                    int cc = c + dirs[i+1];

                    if (rr>=0 && rr<n && cc>=0 && cc<n && grid[rr][cc]==-1) {
                        grid[rr][cc] = dist;
                        bfsQueue.push({rr, cc});
                    }
                }
            }
            ++dist;
        }

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({grid[0][0], {0,0}});
        while(!pq.empty()){
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if (temp.first == n-1 && temp.second == n-1) return safe;
            vis[temp.first][temp.second] = true;

            for (int i=0; i<4; ++i) {
                int newX = temp.first + dirs[i];
                int newY = temp.second + dirs[i+1];

                if (newX>=0 && newX<n && newY>=0 && newY<n && !vis[newX][newY]) {
                    int s = std::min(safe, grid[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }

        return -1;
    }
};