class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        std::reverse(matrix.begin(), matrix.end());
        for (int r=0; r<matrix.size(); ++r) {
            for (int c=r+1; c<matrix[0].size(); ++c) {
                std::swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};