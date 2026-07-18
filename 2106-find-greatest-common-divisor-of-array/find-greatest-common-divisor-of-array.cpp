class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallestNum = nums[0], largestNum = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            smallestNum = std::min(smallestNum, nums[i]);
            largestNum = std::max(largestNum, nums[i]);
        }
        return getGCD(smallestNum, largestNum);
    }

    int getGCD(int a, int b) {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }
};