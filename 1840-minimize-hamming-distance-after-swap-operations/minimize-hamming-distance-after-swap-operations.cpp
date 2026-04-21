class Solution {
private:
    // union find
    vector<int> parent;

    void combine(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent = vector<int>(n);
        for (int i=0; i<n; ++i) {
            parent[i] = i;
        }
        for (vector<int> swap: allowedSwaps) {
            combine(swap[0], swap[1]);
        }

        vector<unordered_map<int, int>> rootIndexToTargetVals(n);
        for (int i=0; i<n; ++i) {
            int rootIndex = find(i);
            ++rootIndexToTargetVals[rootIndex][target[i]];
        }

        int ans = 0;
        for (int i=0; i<n; ++i) {
            int src = source[i], rootIndex = find(i);
            if (rootIndexToTargetVals[rootIndex][src] > 0) {
                --rootIndexToTargetVals[rootIndex][src];
            } else {
                ++ans;
            }
        }
        return ans;
    }
};