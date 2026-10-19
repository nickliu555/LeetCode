class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int numTarget = 0, numLess = 0;
        for (int num: nums) {
            if (num == target) {
                ++numTarget;
            } else if (num < target) {
                ++numLess;
            }
        }
        vector<int> ans;
        for (int i=numLess; i<numLess+numTarget; ++i) {
            ans.push_back(i);
        }
        return ans;
    }
};