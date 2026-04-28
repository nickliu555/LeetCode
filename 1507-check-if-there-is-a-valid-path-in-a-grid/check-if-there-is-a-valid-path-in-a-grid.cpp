class Solution {
private:
    map<pair<int,int>, pair<int,int>> parent;

    pair<int,int> find(pair<int,int> x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void combine(pair<int,int> x, pair<int,int> y) {
        pair<int,int> groupX = find(x);
        pair<int,int> groupY = find(y);
        if (groupX != groupY) {
            parent[groupX] = groupY;
        }
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int r=-1; r<=2*m+1; ++r) {
            for (int c=-1; c<=2*n+1; ++c) {
                parent[{r,c}] = {r,c};
            }
        }

        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == 2 || grid[r][c] == 5 || grid[r][c] == 6) {
                    combine({2*r, 2*c}, {2*r-1, 2*c});
                }
                if (grid[r][c] == 1 || grid[r][c] == 3 || grid[r][c] == 5) {
                    combine({2*r, 2*c}, {2*r, 2*c-1});
                }
                if (grid[r][c] == 2 || grid[r][c] == 3 || grid[r][c] == 4) {
                    combine({2*r, 2*c}, {2*r+1, 2*c});
                }
                if (grid[r][c] == 1 || grid[r][c] == 4 || grid[r][c] == 6) {
                    combine({2*r, 2*c}, {2*r, 2*c+1});
                }
            }
        }

        return find({0,0}) == find({2*m-2, 2*n-2});
    }
};