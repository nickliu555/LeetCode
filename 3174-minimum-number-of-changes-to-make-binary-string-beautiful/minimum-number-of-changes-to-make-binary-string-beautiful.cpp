class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for (int i=0; i<s.length(); i+=2) {
            int numZero = (s[i] == '0') + (s[i+1] == '0');
            ans += std::min(numZero, 2-numZero);
        }
        return ans;
    }
};