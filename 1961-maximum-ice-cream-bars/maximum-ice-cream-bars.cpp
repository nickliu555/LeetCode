class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int ans = 0;
        for (int cost: costs) {
            coins -= cost;
            if (coins >= 0) {
                ++ans;
                if (coins == 0) {
                    break;
                }
            } else {
                break;
            }
        }
        return ans;
    }
};