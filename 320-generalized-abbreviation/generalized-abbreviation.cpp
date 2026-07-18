class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        helper("", 0, word, ans);
        return ans;
    }

    void helper(string currAbbr, int index, string word, vector<string>& ans) {
        if (index >= word.length()) {
            ans.push_back(currAbbr);
            return;
        }

        // use length to abbreviate
        if (currAbbr.empty() || !std::isdigit(currAbbr.back())) {
            int maxLen = word.length() - index;
            for (int len=1; len<=maxLen; ++len) {
                helper(currAbbr+std::to_string(len), index+len, word, ans);
            }
        }
        // just use the letters
        helper(currAbbr+word[index], index+1, word, ans);
    }
};