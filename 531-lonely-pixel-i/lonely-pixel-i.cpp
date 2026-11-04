class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size(), ans = 0;
        vector<int> rowCount(m, 0), colCount(n, 0);

        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (picture[r][c] == 'B') {
                    ++rowCount[r], ++colCount[c];
                }
            }
        }
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (picture[r][c] == 'B' && rowCount[r] == 1 && colCount[c] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};