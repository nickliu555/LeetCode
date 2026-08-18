class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == nums.size()) {
            int max = nums[0];
            for (int num: nums) {
                max = std::max(max, num);
            }
            return max;
        } else if (k == 1) {
            unordered_map<int, int> count;
            for (int num: nums) {
                ++count[num];
            }
            int ans = -1;
            for (int num: nums) {
                if (count[num] == 1 && num > ans) {
                    ans = num;
                }
            }
            return ans;
        }

        if (nums[0] == nums.back()) return -1;
        int firstCount = 0, lastCount = 0;
        for (int num: nums) {
            if (num == nums[0]) {
                ++firstCount;
            } else if (num == nums.back()) {
                ++lastCount;
            }
        }

        if (firstCount == 1 && lastCount == 1) {
            return std::max(nums[0], nums.back());
        } else if (firstCount == 1) {
            return nums[0];
        } else if (lastCount == 1) {
            return nums.back();
        }
        return -1;
    }
};