class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        for (int digit=0; digit<num; ++digit) {
            int currDigit = std::min(9, sum);
            sum -= currDigit;
            ans += std::to_string(currDigit);
        }
        return sum > 0 ? "" : ans;
    }
};