class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        long long ans = 0;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (vector<int> interval: intervals) {
            while (!minHeap.empty() && minHeap.top() < interval[0]) {
                minHeap.pop();
            }
            ans += minHeap.size();
            minHeap.push(interval[1]);
        }
        return ans;
    }
};