class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans(num, ' ');
        for (int i=0; i<num; ++i) {
            int currDigit = std::min(9, sum);
            sum -= currDigit;
            ans[i] = '0' + currDigit;
        }
        return sum > 0 ? "" : ans;
    }
};