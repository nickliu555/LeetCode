class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
         std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> queriesWithIndex;
        for (int i=0; i<queries.size(); ++i) {
            queriesWithIndex.push_back({queries[i], i});
        }
        std::sort(queriesWithIndex.begin(), queriesWithIndex.end());

        vector<int> ans(queries.size());
        int l = 0, r = 0;
        unordered_map<int, int> serversRequestCount;
        for (pair<int, int> entry: queriesWithIndex) {
            int index = entry.second;
            int start = entry.first-x, end = entry.first;

            while (r < logs.size() && logs[r][1] <= end) {
                ++serversRequestCount[logs[r][0]];
                ++r;
            }
            while (l < logs.size() && logs[l][1] < start) {
                --serversRequestCount[logs[l][0]];
                if (serversRequestCount[logs[l][0]] == 0) {
                    serversRequestCount.erase(logs[l][0]);
                }
                ++l;
            }
            ans[index] = n - serversRequestCount.size();
        }
        return ans;
    }
};