class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int currNumCommon = 0, n = A.size();
        unordered_map<int, int> count;
        for (int i=0; i<n; ++i) {
            ++count[A[i]];
            if (count[A[i]] <= 0) ++currNumCommon;
            --count[B[i]];
            if (count[B[i]] >= 0) ++currNumCommon;
            ans.push_back(currNumCommon);
        }
        return ans;
    }
};