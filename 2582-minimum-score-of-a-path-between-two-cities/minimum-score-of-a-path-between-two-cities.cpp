class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n+1, vector<pair<int,int>>());
        for (vector<int> road: roads) {
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }

        int ans = INT_MAX;
        vector<bool> visited(n+1, false);
        queue<int> bfsQueue;
        bfsQueue.push(1); visited[1] = true;
        while (!bfsQueue.empty()) {
            int curr = bfsQueue.front();
            bfsQueue.pop();
            for (auto& [node, dist] : adjList[curr]) {
                ans = std::min(ans, dist);
                if (!visited[node]) {
                    visited[node] = true;
                    bfsQueue.push(node);
                }
            }
        }

        return ans;
    }
};