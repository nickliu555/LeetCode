class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, currIncr = 1, currDecr = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                ++currIncr;
                ans = std::max(ans, currIncr);
            } else {
                currIncr = 1;
            }
        }

        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                ++currDecr;
                ans = std::max(ans, currDecr);
            } else {
                currDecr = 1;
            }
        }
        return ans;
    }
};