class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return std::abs(a) > std::abs(b);
        });
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            if (i < n/2 + n%2) {
                ans += nums[i] * nums[i];
            } else {
                ans -= nums[i] * nums[i];
            }
        }
        return ans;
    }
};