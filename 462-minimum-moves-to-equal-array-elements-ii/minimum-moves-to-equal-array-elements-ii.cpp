class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int mid = nums[nums.size()/2], ans = 0;
        for (int num: nums) {
            ans += std::abs(num - mid);
        }
        return ans;
    }
};