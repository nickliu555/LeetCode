class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        unordered_map<int, bool> hasBeenValid;
        for (int num=1; num<=n; ++num) {
            if (isValid(num, hasBeenValid)) {
                ++ans;
            }
        }
        return ans;
    }

    bool isValid(int n, unordered_map<int, bool>& hasBeenValid) {
        bool validFound = false;
        unordered_set<int> rotatable = {2, 5, 6 , 9};
        unordered_set<int> unrotatable = {3, 4, 7};
        while (n > 0) {
            if (hasBeenValid.count(n) > 0) {
                validFound = validFound || hasBeenValid[n];
                break;
            }

            int digit = n % 10;
            if (rotatable.count(digit) > 0) {
                validFound = true;
            } else if (unrotatable.count(digit) > 0) {
                return false;
            }
            n /= 10;
        }
        hasBeenValid[n] = validFound;
        return validFound;
    }
};