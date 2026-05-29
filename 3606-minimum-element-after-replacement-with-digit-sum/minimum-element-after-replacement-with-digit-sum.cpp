class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int i=0; i<nums.size(); ++i) {
            int curr = 0;
            while (nums[i] > 0) {
                curr += nums[i] % 10;
                nums[i] /= 10;
            }
            nums[i] = curr;
            ans = std::min(ans, curr);
        }
        return ans;
    }
};