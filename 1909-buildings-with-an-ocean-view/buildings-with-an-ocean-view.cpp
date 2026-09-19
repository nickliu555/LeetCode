class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> decrMonoStk;
        for (int i=0; i<heights.size(); ++i) {
            while (!decrMonoStk.empty() && heights[decrMonoStk.top()] <= heights[i]) {
                decrMonoStk.pop();
            }
            decrMonoStk.push(i);
        }

        vector<int> ans(decrMonoStk.size());
        while (!decrMonoStk.empty()) {
            ans[decrMonoStk.size()-1] = decrMonoStk.top();
            decrMonoStk.pop();
        }
        return ans;
    }
};