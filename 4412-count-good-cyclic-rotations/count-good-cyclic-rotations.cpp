class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long n = nums.size(), prefixSum = 0, suffixSum = 0;
        for (int i=0; i<n; ++i) {
            if (i < n/2) {
                prefixSum += nums[i];
                nums.push_back(nums[i]);
            } else {
                suffixSum += nums[i];
            }
        }

        int ans = 0;
        if (prefixSum > suffixSum) ++ans;
        for (int i=0, j=n/2; i<n-1; ++i, ++j) {
            prefixSum -= nums[i];
            prefixSum += nums[j];
            suffixSum -= nums[j];
            suffixSum += nums[i];
            if (prefixSum > suffixSum) ++ans;
        }
        return ans;
    }
};