class Solution {
public:
    bool confusingNumber(int n) {
        // return true if
        // 1. no invalid digits
        // 2. new num is different than original num

        unordered_set<int> invalid = {2, 3 ,4, 5, 7};
        int originalNum = n, currNum = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (invalid.count(digit) > 0) {
                return false;
            }

            if (digit == 6) {
                currNum = (currNum * 10) + 9;
            } else if (digit == 9) {
                currNum = (currNum * 10) + 6;
            } else {
                currNum = (currNum * 10) + digit;
            }
        }

        return currNum != originalNum;
    }
};