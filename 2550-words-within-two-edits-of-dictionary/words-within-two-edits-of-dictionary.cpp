class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (string query: queries) {
            if (canEdit(query, dictionary)) {
                ans.push_back(query);
            }
        }
        return ans;
    }

    bool canEdit(string query, vector<string>& dictionary) {
        for (string dictWord: dictionary) {
            int numDiff = 0;
            for (int i=0; i<query.length(); ++i) {
                if (query[i] != dictWord[i]) {
                    ++numDiff;
                    if (numDiff > 2) break;
                }
            }
            if (numDiff <= 2) return true;
        }
        return false;
    }
};
