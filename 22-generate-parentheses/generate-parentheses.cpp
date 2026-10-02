class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        helper(n, 0, curr, ans);
        return ans;
    }

    void helper(int openParenNeeded, int closedParenNeeded, string& curr, vector<string>& ans) {
        if (openParenNeeded == 0 && closedParenNeeded == 0) {
            ans.push_back(curr);
            return;
        }

        if (openParenNeeded > 0) {
            curr += "(";
            --openParenNeeded;
            ++closedParenNeeded;

            helper(openParenNeeded, closedParenNeeded, curr, ans);

            curr.pop_back();
            ++openParenNeeded;
            --closedParenNeeded;
        }

        if (closedParenNeeded > 0) {
            curr += ")";
            --closedParenNeeded;

            helper(openParenNeeded, closedParenNeeded, curr, ans);

            curr.pop_back();
            ++closedParenNeeded;
        }
    }
};