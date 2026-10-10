class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int,int>>> adjList(n, vector<pair<int,int>>());
        for (vector<int> highway: highways) {
            adjList[highway[0]].push_back({highway[1], highway[2]});
            adjList[highway[1]].push_back({highway[0], highway[2]});
        }

        // {cost, node, discountsLeft}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0,0,discounts});
        // visited[i][j] = min cost so far to get to i with j discounts left
        vector<vector<int>> visited(n, vector<int>(discounts+1));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<=discounts; ++j) {
                visited[i][j] = INT_MAX;
            }
        }
        visited[0][discounts] = 0;

        while (!minHeap.empty()) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            int cost = curr[0], node = curr[1], discountsLeft = curr[2];
            if (node == n-1) {
                return cost;
            }

            for (pair<int,int> adj: adjList[node]) {
                int nextNode = adj.first, toll = adj.second;

                // use discount
                if (discountsLeft > 0 && visited[nextNode][discountsLeft-1] > cost + toll/2) {
                    visited[nextNode][discountsLeft-1] = cost + toll/2;
                    minHeap.push({cost + toll/2, nextNode, discountsLeft-1});
                }

                // dont use discount
                if (visited[nextNode][discountsLeft] > cost + toll) {
                    visited[nextNode][discountsLeft] = cost + toll;
                    minHeap.push({cost + toll, nextNode, discountsLeft});
                }
            }
        }
        return -1;
    }
};