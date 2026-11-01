class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = nums[0];
        for (int num: nums) {
            minNum = std::min(minNum, num);
        }
        int ans = 0;
        for (int num: nums) {
            ans += num - minNum;
        }
        return ans;
    }
};