class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans = 0, max_i = 0;
        for (int j=k; j<nums.size(); ++j) {
            max_i = std::max(max_i, nums[j-k]);
            ans = std::max(ans, max_i+nums[j]);
        }
        return ans;
    }
};