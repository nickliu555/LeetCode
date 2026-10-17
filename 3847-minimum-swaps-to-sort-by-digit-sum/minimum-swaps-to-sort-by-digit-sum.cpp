class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>> sortedNums;
        for (int i=0; i<nums.size(); ++i) {
            sortedNums.push_back({getSumDigits(nums[i]), nums[i], i});
        }
        std::sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            while (sortedNums[i][2] != i) {
                std::swap(sortedNums[i], sortedNums[sortedNums[i][2]]);
                ++ans;
            }
        }
        return ans;
    }

    int getSumDigits(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
};