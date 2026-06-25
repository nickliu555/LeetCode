class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string firstRow(n, '.');
        ans.push_back(firstRow);
        for (int i=1; i<m; ++i) {
            string row(n-1, '#');
            row += '.';
            ans.push_back(row);
        }
        return ans;
    }
};