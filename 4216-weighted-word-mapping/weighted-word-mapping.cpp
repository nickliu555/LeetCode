class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string word: words) {
            int weight = 0;
            for (char letter: word) {
                weight += weights[letter-'a'];
            }
            weight %= 26;
            ans += 'a' + (25 - weight);
        }
        return ans;
    }
};