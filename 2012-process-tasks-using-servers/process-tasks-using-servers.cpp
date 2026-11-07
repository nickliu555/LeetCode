class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> availableServers;
        for (int i=0; i<n; ++i) {
            availableServers.push({servers[i], i});
        }
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<>> busyServers;
        
        vector<int> ans(m);
        long time = 0;
        for (int i=0; i<m; ++i) {
            time = std::max((long)i, time);
            // do a time skip if no immediate available server
            if (availableServers.empty() && busyServers.top().first > time) {
                time = busyServers.top().first;
            }

            while (!busyServers.empty() && busyServers.top().first <= time) {
                int index = (int)busyServers.top().second;
                availableServers.push({servers[index], index});
                busyServers.pop();
            }
            
            pair<int,int> info = availableServers.top();
            busyServers.push({time + tasks[i], info.second});
            ans[i] = info.second;
            availableServers.pop();
        }
        return ans;
    }
};