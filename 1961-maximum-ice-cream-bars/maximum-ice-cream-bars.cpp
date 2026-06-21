class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i=0; i<costs.size() && coins>=0; ++i) {
            coins -= costs[i];
            if (coins >= 0) {
                ++ans;
            }
        }
        return ans;
    }
};