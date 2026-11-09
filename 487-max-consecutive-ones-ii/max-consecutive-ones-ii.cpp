class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        bool hasFlipped = false;
        for (int l=0, r=0; r<nums.size(); ++r) {
            if (nums[r] == 0) {
                if (!hasFlipped) {
                    hasFlipped = true;
                } else {
                    while (nums[l] == 1) {
                        ++l;
                    }
                    ++l;
                }
            }
            ans = std::max(ans, r-l+1);
        }
        return ans;
    }
};