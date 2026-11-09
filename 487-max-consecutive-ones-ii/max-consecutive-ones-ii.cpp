class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> numConsecutiveOnesOnRight(n, 0);
        for (int i=n-2; i>=0; --i) {
            if (nums[i+1] == 1) {
                numConsecutiveOnesOnRight[i] = 1 + numConsecutiveOnesOnRight[i+1];
            } else {
                numConsecutiveOnesOnRight[i] = 0;
            }
        }

        int numConsecutiveOnesOnLeft = 0, ans = 0;
        for (int i=0; i<n; ++i) {
            ans = std::max(ans, numConsecutiveOnesOnLeft + 1 + numConsecutiveOnesOnRight[i]);
            if (nums[i] == 1) {
                ++numConsecutiveOnesOnLeft;
            } else {
                numConsecutiveOnesOnLeft = 0;
            }
        }
        return ans;
    }
};