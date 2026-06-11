class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1, mod = 1e9 + 7;
        vector<vector<int>> adjList(n+1, vector<int>());
        for (vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<pair<int,int>> bfsQueue;
        bfsQueue.push({1, 0});
        int height = -1;
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            for (int i=0; i<size; ++i) {
                int curr = bfsQueue.front().first;
                int prev = bfsQueue.front().second;
                bfsQueue.pop();

                for (int adj: adjList[curr]) {
                    if (adj != prev) {
                        bfsQueue.push({adj, curr});
                    }
                }
            }
            ++height;
        }

        long long result = 1;
        int exp = height - 1;
        while (exp > 0) {
            result = (result * 2) % mod;
            exp--;
        }
        return result;
    }
};