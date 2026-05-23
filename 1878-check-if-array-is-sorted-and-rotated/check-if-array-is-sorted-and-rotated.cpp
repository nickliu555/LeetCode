class Solution {
public:
    bool check(vector<int>& nums) {
        bool seenDip = false;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] < nums[i-1]) {
                if (seenDip) {
                    return false;
                }
                seenDip = true;
            }
            if (seenDip) {
                if (nums[i] > nums[0]) {
                    return false;
                }
            }
        }
        return true;
    }
};