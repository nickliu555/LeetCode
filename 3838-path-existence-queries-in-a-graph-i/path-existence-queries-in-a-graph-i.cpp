class Solution {
private:
    vector<int> parent;

    int Find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        int groupX = Find(x);
        int groupY = Find(y);

        parent[groupX] = groupY;
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent = vector<int>(n);
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }

        for (int i=1; i<n; ++i) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                Union(i, i-1);
            }
        }

        vector<bool> ans;
        for (vector<int> query: queries) {
            if (Find(query[0]) == Find(query[1])) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};