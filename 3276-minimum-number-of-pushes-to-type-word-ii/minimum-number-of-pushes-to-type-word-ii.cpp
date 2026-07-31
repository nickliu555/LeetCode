class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> count;
        for (char letter: word) {
            ++count[letter];
        }

        vector<int> countVal;
        for (pair<char, int> c: count) {
            countVal.push_back(c.second);
        }
        std::sort(countVal.begin(), countVal.end(), greater<>());

        int ans = 0, numPress = 1, numKeysLeft = 8;
        for (int val: countVal) {
            ans += numPress * val;
            --numKeysLeft;
            if (numKeysLeft == 0) {
                ++numPress;
                numKeysLeft = 8;
            }
        }
        return ans;
    }
};