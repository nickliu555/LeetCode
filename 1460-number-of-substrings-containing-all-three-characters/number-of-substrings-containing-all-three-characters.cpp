class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> count;
        int ans = 0, n = s.length();
        for (int i=0, j=0; j<n; ++j) {
            ++count[s[j]];
            while (count.size() == 3) {
                ans += (n - j);
                --count[s[i]];
                if (count[s[i]] == 0) {
                    count.erase(s[i]);
                }
                ++i;
            }
        }
        return ans;
    }
};