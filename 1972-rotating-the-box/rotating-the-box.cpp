class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();

        // 1. shift stones to the right
        for (int r=0; r<m; ++r) {
            for (int i=n-1, j=n-1; j>=0; --j) {
                if (box[r][j] == '#') {
                    std::swap(box[r][j], box[r][i]);
                    --i;
                } else if (box[r][j] == '*') {
                    i = j - 1;
                }
            }
        }

        // 2. rotate 90 degrees clockwise
        vector<vector<char>> ans(n, vector<char>(m));
        for (int c=0; c<n; ++c) {
            for (int r=m-1; r>=0; --r) {
                ans[c][m-1-r] = box[r][c];
            }
        }

        return ans;
    }
};