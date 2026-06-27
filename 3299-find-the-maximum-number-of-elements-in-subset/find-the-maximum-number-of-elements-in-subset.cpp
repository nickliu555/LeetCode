class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num: nums) ++count[num];
        
        std::sort(nums.begin(), nums.end(), greater<int>());
        unordered_map<int, int> dp;
        int ans = 1;
        for (int num: nums) {
            if (num == 1) {
                ans = std::max(ans, count[1] - (count[1]%2==0));
            } else {
                dp[num] = 1;
                if (count[num] >= 2 && num <= std::sqrt(std::numeric_limits<int>::max())) {
                    int squared = num * num;
                    dp[num] = dp[squared] + 1;
                    ans = std::max(ans, dp[num]*2-1);
                }
            }
        }
        return ans;
    }
};