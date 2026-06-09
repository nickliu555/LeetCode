class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max = nums[0], min = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            max = std::max(max, nums[i]);
            min = std::min(min, nums[i]);
        }
        return (long long)(max - min) * k;
    }
};