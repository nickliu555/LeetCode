class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int num=1; num<=n; ++num) {
            if (isValid(num)) {
                ++ans;
            }
        }
        return ans;
    }

    bool isValid(int n) {
        bool validFound = false;
        unordered_set<int> rotatable = {2, 5, 6 , 9};
        unordered_set<int> unrotatable = {3, 4, 7};
        while (n > 0) {
            int digit = n % 10;
            if (rotatable.count(digit) > 0) {
                validFound = true;
            } else if (unrotatable.count(digit) > 0) {
                return false;
            }
            n /= 10;
        }
        return validFound;
    }
};