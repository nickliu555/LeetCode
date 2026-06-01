class Solution {
public:
    int minimumCost(vector<int>& cost) {
        std::sort(cost.begin(), cost.end(), std::greater<>());
        int ans = 0;
        for (int i=0; i<cost.size(); ++i) {
            if (i % 3 < 2) {
                ans += cost[i];
            }
        }
        return ans;
    }
};