class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, greater<>> minHeap;
        for (int num: nums) {
            string rearrangedStr = std::to_string(num);
            std::sort(rearrangedStr.rbegin(), rearrangedStr.rend());
            int rearrangedNum = std::stoi(rearrangedStr);
            minHeap.push(rearrangedNum-num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        long long ans = 0;
        for (int num: nums) {
            ans += num;
        }
        while (!minHeap.empty()) {
            ans += minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};