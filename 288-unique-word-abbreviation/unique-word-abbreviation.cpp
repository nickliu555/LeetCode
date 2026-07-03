class ValidWordAbbr {
private:
    unordered_map<string, string> abbrToWord;

    string convertToAbbr(string word) {
        if (word.length() <= 2) return word;
        return word.front() + std::to_string(word.length()-2) + word.back();
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string word: dictionary) {
            string abbr = convertToAbbr(word);
            if (abbrToWord.count(abbr) > 0 && abbrToWord[abbr] != word) {
                abbrToWord[abbr] = "";
            } else {
                abbrToWord[abbr] = word;
            }
        }
    }
    
    bool isUnique(string word) {
        string abbr = convertToAbbr(word);
        if (abbrToWord.count(abbr) == 0) return true;
        return abbrToWord[abbr] == word;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */