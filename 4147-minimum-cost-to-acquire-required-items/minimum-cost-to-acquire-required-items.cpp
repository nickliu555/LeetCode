class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int minBoth = std::min(costBoth, cost1+cost2);
        long long ans = std::min(need1, need2) * (long long)minBoth;
        if (need2 > need1) {
            int diff = need2 - need1;
            ans += (long long)diff * std::min(cost2, costBoth);
        } else if (need1 > need2) {
            int diff = need1 - need2;
            ans += (long long)diff * std::min(cost1, costBoth);
        }
        return ans;
    }
};