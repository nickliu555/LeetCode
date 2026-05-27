class Solution {
public:
    int numberOfSpecialChars(string word) {
        // 0 - start/default state
        // 1 - seen lower-case
        // 2 - seen lower-case and then upper-case
        // -1 - bad state
        unordered_map<char, int> state;
        int ans = 0;
        for (char c: word) {
            if (std::isupper(c)) {
                int lowerC = std::tolower(c);
                if (state[lowerC] == 0) {
                    state[lowerC] = -1;
                } else if (state[lowerC] == 1) {
                    state[lowerC] = 2;
                    ++ans;
                }
            } else {
                if (state[c] == 0) {
                    state[c] = 1;
                } else if (state[c] == 2) {
                    state[c] = -1;
                    --ans;
                }
            }
        }
        return ans;
    }
};