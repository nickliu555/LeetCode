class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string newS = "";
            for (int i=0; i<s.length(); i+=k) {
                int groupSum = 0, groupSize = std::min(k, (int)s.length()-i);
                for (int j=i; j<i+groupSize; ++j) {
                    groupSum += s[j] - '0';
                }
                newS += std::to_string(groupSum);
            }
            s = newS;
        }
        return s;
    }
};