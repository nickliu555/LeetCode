class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        for (char c: text) ++count[c];

        int ans = count['b'];
        ans = std::min(ans, count['a']);
        ans = std::min(ans, count['l'] / 2);
        ans = std::min(ans, count['o'] / 2);
        ans = std::min(ans, count['n']);
        return ans;
    }
};