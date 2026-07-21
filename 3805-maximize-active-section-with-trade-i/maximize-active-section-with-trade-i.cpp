class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int numActive = 0, maxDelta = 0, prevInactive = 0, postInactive = 0, n = s.length();
        for (int i=0; i<n; ++i) {
            if (s[i] == '1') {
                ++numActive;
            } else {
                if (i == 0 || s[i-1] == '1') {
                    prevInactive = postInactive;
                    postInactive = 0;
                }

                ++postInactive;
                if (prevInactive > 0) {
                    maxDelta = std::max(maxDelta, prevInactive + postInactive);
                }
            }
        }
        return numActive + maxDelta;
    }
};