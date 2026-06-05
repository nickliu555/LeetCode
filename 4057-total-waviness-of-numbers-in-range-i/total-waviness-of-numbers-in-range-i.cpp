class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int num=num1; num<=num2; ++num) {
            int tmp = num;
            int prev = tmp % 10;
            tmp /= 10;
            if (tmp == 0) continue;
            int curr = tmp % 10;
            tmp /= 10;
            if (tmp == 0) continue;
            int next = tmp % 10;

            while (tmp > 0) {
                if ((curr < prev && curr < next) || (curr > prev && curr > next)) {
                    ++ans;
                }
                prev = curr;
                curr = next;
                tmp /= 10;
                next = tmp % 10;
            }
        }
        return ans;
    }
};