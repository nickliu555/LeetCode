class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        unordered_set<string> visited;
        vector<int> curr = {0, 0};
        visited.insert("0-0");

        while (true) {
            vector<int> next;
            if (grid[curr[0]][curr[1]] == 'L') {
                next = {curr[0], curr[1]-1};
            } else if (grid[curr[0]][curr[1]] == 'R') {
                next = {curr[0], curr[1]+1};
            } else if (grid[curr[0]][curr[1]] == 'U') {
                next = {curr[0]-1, curr[1]};
            } else {
                next = {curr[0]+1, curr[1]};
            }

            if (next[0] < 0 || next[0] >= grid.size() || next[1] < 0 || next[1] >= grid[0].size() || visited.count(getCellStr(next)) > 0) {
                return curr;
            }
            curr = next;
            visited.insert(getCellStr(next));
        }

        return {}; // should never be reached
    }

    string getCellStr(vector<int> cell) {
        return std::to_string(cell[0]) + "-" + std::to_string(cell[1]);
    }
};