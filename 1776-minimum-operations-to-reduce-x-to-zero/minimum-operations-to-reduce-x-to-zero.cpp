class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0, n = nums.size();
        for (int num: nums) {
            totalSum += num;
        }
        int target = totalSum - x;
        if (target < 0) {
            return -1;
        }

        int ans = n+1, currSum = 0;
        for (int l=0, r=0; r<n; ++r) {
            currSum += nums[r];
            while (currSum > target) {
                currSum -= nums[l];
                ++l;
            }
            if (currSum == target) {
                ans = std::min(ans, n - r + l - 1);
            }
        }
        return ans == n+1 ? -1 : ans;
    }
};