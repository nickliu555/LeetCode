class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev1 = 0, prev2 = 10e7, prev3 = 10e7;
        for (int i=0; i<n; ++i) {
            int curr = std::min({prev1+costs[i]+1, prev2+costs[i]+4, prev3+costs[i]+9});
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};