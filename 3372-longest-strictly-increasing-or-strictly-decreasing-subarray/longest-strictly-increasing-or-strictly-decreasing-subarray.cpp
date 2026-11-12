class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, currIncrLen = 1, currDecrLen = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                ++currIncrLen;
                ans = std::max(ans, currIncrLen);
                currDecrLen = 1;
            } else if (nums[i] < nums[i-1]) {
                ++currDecrLen;
                ans = std::max(ans, currDecrLen);
                currIncrLen = 1;
            } else {
                currIncrLen = 1;
                currDecrLen = 1;
            }
        }
        return ans;
    }
};