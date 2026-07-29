class Solution {
public:
    string longestWord(vector<string>& words) {
        // sort words by length
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length(); 
        });

        // a word will only be in wordsWithAllPrefixes if all of its prefixes are also in wordsWithAllPrefixes
        unordered_set<string> wordsWithAllPrefixes;
        wordsWithAllPrefixes.insert("");
        string ans = "";
        for (string word: words) {
            // if the prefix substr(0., len-1) is in wordsWithAllPrefixes
            // (meaning the rest of the prefixes must also be in wordsWithAllPrefixes)
            if (wordsWithAllPrefixes.count(word.substr(0, word.length()-1)) > 0) {
                wordsWithAllPrefixes.insert(word);
                if (word.length()>ans.length() || (word.length()==ans.length() && word<ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};