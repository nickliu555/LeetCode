class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int ans = 0, maxR = 0;
        for (vector<int> interval: intervals) {
            if (interval[1] > maxR) {
                ++ans;
                maxR = interval[1];
            }
        }
        return ans;
    }
};