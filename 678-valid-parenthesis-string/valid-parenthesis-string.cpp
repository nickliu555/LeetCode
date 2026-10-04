class Solution {
public:
    bool checkValidString(string s) {
        int cMin = 0, cMax = 0;
        for (char c: s) {
            if (c == '(') {
                ++cMax, ++cMin;
            }
            else if (c == ')'){
                --cMax, cMin = max(cMin - 1, 0);
            }
            else if (c == '*') {
                ++cMax, cMin = max(cMin - 1, 0);
            }
            if (cMax < 0) {
                return false;
            }
        }
        return cMin == 0;
    }
};