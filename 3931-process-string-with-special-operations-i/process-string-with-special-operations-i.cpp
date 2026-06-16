class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c: s) {
            if (c == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else if (c == '#') {
                result += result;
            } else if (c == '%') {
                result = reverseString(result);
            } else {
                result += c;
            }
        }
        return result;
    }

    string reverseString(string str) {
        for (int i=0, j=str.length()-1; i<j; ++i, --j) {
            std::swap(str[i], str[j]);
        }
        return str;
    }
};