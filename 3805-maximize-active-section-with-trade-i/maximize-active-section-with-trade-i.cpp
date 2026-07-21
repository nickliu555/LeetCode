class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int numActive = 0, maxDelta = 0, prevInactive = 0, postInactive = 0, n = s.length();
        s = '1' + s + '1';
        for (int i=1; i<=n; ++i) {
            if (s[i] == '1') {
                ++numActive;
            } else {
                if (s[i-1] == '1') {
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