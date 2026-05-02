class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        // dp[i] = 0, invalid number
        // dp[i] = 1, valid and same number
        // dp[i] = 2, valid and different number
        unordered_map<int, int> dp;
        for (int num=1; num<=n; ++num) {
            if (isValid(num, dp)) {
                ++ans;
            }
        }
        return ans;
    }

    bool isValid(int n, unordered_map<int, int>& dp) {
        bool diffFound = false;
        unordered_set<int> rotatable = {2, 5, 6 , 9};
        unordered_set<int> unrotatable = {3, 4, 7};
        int originalNum = n;
        while (n > 0) {
            if (dp.count(n) > 0) {
                if (dp[n] == 0) {
                    dp[originalNum] = 0;
                    return false;
                } else if (dp[n] == 1) {
                    dp[originalNum] = diffFound ? 2 : 1;
                    return dp[originalNum] == 2;
                } else {
                    dp[originalNum] = 2;
                    return true;
                }
            }

            int digit = n % 10;
            if (rotatable.count(digit) > 0) {
                diffFound = true;
            } else if (unrotatable.count(digit) > 0) {
                dp[originalNum] = 0;
                return false;
            }
            n /= 10;
        }
        dp[n] = diffFound ? 2 : 1;
        return diffFound;
    }
};