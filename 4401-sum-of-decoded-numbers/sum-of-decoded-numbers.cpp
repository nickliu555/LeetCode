class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0, mod = 1e9+7;
        for (long long num: nums) {
            long long width = num % 10;
            long long d = num / 10;
            string dStr = std::to_string(d);
            string xString = dStr.substr(0, width), yString = dStr.substr(width);
            long long x = std::stoll(xString), y = std::stoll(yString);
            ans += calculatePower(x, y, mod);
        }
        ans %= mod;
        return ans;
    }

    long long calculatePower(long long x, long long y, int MOD) {
        long long result = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            y = y / 2;
        }
        return result;
    }
};