class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> keyToValue;
        for (vector<string> entry: knowledge) {
            keyToValue[entry[0]] = entry[1];
        }

        string ans = "";
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '(') {
                string key = "";
                ++i;
                while (s[i] != ')') {
                    key += s[i];
                    ++i;
                }
                if (keyToValue.count(key) == 0) {
                    ans += "?";
                } else {
                    ans += keyToValue[key];
                }
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};