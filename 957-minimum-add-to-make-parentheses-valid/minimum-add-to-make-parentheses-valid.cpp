class Solution {
public:
    int minAddToMakeValid(string s) {
        int numOpenNeeded = 0, numClosedNeeded = 0;
        for (char c: s) {
            if (c == '(') {
                ++numClosedNeeded;
            } else {
                if (numClosedNeeded == 0) {
                    ++numOpenNeeded;
                } else {
                    --numClosedNeeded;
                }
            }
        }
        return numOpenNeeded + numClosedNeeded;
    }
};