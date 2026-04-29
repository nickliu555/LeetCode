class Solution {
private:
    unordered_map<int, int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void combine(int x, int y) {
        int groupX = find(x);
        int groupY = find(y);
        if (groupX != groupY) {
            parent[groupX] = groupY;
        }
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int r=-1; r<=2*m+1; ++r) {
            for (int c=-1; c<=2*n+1; ++c) {
                int cellIndex = getCellIndex(r,c,2*n);
                parent[cellIndex] = cellIndex;
            }
        }

        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == 2 || grid[r][c] == 5 || grid[r][c] == 6) {
                    combine(getCellIndex(2*r, 2*c, 2*n), getCellIndex(2*r-1, 2*c, 2*n));
                }
                if (grid[r][c] == 1 || grid[r][c] == 3 || grid[r][c] == 5) {
                    combine(getCellIndex(2*r, 2*c, 2*n), getCellIndex(2*r, 2*c-1, 2*n));
                }
                if (grid[r][c] == 2 || grid[r][c] == 3 || grid[r][c] == 4) {
                    combine(getCellIndex(2*r, 2*c, 2*n), getCellIndex(2*r+1, 2*c, 2*n));
                }
                if (grid[r][c] == 1 || grid[r][c] == 4 || grid[r][c] == 6) {
                    combine(getCellIndex(2*r, 2*c, 2*n), getCellIndex(2*r, 2*c+1, 2*n));
                }
            }
        }

        return find(getCellIndex(0, 0, 2*n)) == find(getCellIndex(2*m-2, 2*n-2, 2*n));
    }

    int getCellIndex(int i, int j, int c) {
        return i * c + j;
    }
};