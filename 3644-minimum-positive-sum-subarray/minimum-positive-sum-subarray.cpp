class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int len=l; len<=r; ++len) {
            int windowSum = 0;
            for (int a=0, b=0; b<nums.size(); ++b) {
                windowSum += nums[b];
                if (b-a+1 == len) {
                    if (windowSum > 0) {
                        ans = std::min(ans, windowSum);
                    }
                    windowSum -= nums[a];
                    ++a;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};