class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProduct = 1, originalNum = n;
        while (n > 0) {
            int currDigit = n % 10;
            digitSum += currDigit;
            digitProduct *= currDigit;
            n /= 10;
        }
        return originalNum % (digitSum + digitProduct) == 0;
    }
};