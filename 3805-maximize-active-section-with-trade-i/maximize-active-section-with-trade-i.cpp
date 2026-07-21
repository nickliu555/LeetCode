class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int numActive = 0, maxDelta = 0, prevInactive = 0, currInactive = 0;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '1') {
                ++numActive;
            } else {
                if (i == 0 || s[i-1] == '1') {
                    prevInactive = currInactive;
                    currInactive = 0;
                }

                ++currInactive;
                if (prevInactive > 0) {
                    maxDelta = std::max(maxDelta, prevInactive + currInactive);
                }
            }
        }
        return numActive + maxDelta;
    }
};