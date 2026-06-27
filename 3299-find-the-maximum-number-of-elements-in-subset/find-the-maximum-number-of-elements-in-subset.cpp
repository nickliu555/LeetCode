class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num: nums) ++count[num];
        
        unordered_map<int, int> dp;
        int ans = 1;
        for (int num: nums) {
            if (dp[num] > 0) continue;

            if (num == 1) {
                ans = std::max(ans, count[1] - (count[1]%2==0));
            } else {
                int len = dfs(num, count, dp);
                ans = std::max(ans, len*2-1);
            }
        }
        return ans;
    }

    int dfs(int num, unordered_map<int, int>& count, unordered_map<int, int>& dp) {
        if (count[num] == 0) return 0;

        int ans = 1;
        if (count[num] >= 2 && num <= std::sqrt(std::numeric_limits<int>::max())) {
            int squared = num * num;
            ans = 1 + dfs(squared, count, dp);
        }
        dp[num] = ans;
        return ans;
    }
};