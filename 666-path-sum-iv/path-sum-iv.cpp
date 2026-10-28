class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> pathSum(6, vector<int>(17, 0));
        vector<vector<bool>> exists(6, vector<bool>(17, false));
        int maxDepth = 1;
        for (int num: nums) {
            int v = num % 10;
            num /= 10;
            int p = num % 10;
            num /= 10;
            int d = num% 10;

            maxDepth = std::max(maxDepth, d);
            pathSum[d][p] = pathSum[d-1][(p+1)/2] + v;
            exists[d][p] = true;
        }

        int ans = 0;
        for (int num : nums) {
            int p = (num / 10) % 10;
            int d = num / 100;
            
            if (!exists[d+1][2*p-1] && !exists[d+1][2*p]) {
                ans += pathSum[d][p];
            }
        }
        return ans;
    }
};