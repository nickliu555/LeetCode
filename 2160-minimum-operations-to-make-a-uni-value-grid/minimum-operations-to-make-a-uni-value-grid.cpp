class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> allVals;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                allVals.push_back(grid[r][c]);
            }
        }

        std::sort(allVals.begin(), allVals.end());
        int midElement = allVals[allVals.size() / 2];
        int ans = 0;
        for (int val: allVals) {
            if (std::abs(midElement-val) % x != 0) return -1;
            ans += std::abs(midElement-val) / x;
        }

        return ans;
    }
};