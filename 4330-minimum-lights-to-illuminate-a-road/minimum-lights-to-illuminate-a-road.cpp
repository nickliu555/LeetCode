class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> lightsDiff(n, 0);
        for (int i=0; i<n; ++i) {
            if (lights[i] > 0) {
                ++lightsDiff[std::max(0, i-lights[i])];
                if (i+lights[i]+1 < n) {
                    --lightsDiff[i+lights[i]+1];
                }
            }
        }

        int numInstall = 0, currLight = 0;
        for (int i=0; i<n; ++i) {
            currLight += lightsDiff[i];
            if (currLight == 0) {
                ++numInstall;
                ++currLight;
                if (i+3 < n) {
                    --lightsDiff[i+3];
                }
            }
        }
        return numInstall;
    }
};