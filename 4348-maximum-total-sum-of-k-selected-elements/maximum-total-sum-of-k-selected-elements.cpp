class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for(int num: nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        long long ans = 0, x = mul - k + 1;
        while (!minHeap.empty()) {
            if (x > 1) {
                ans += x * minHeap.top();
            } else {
                ans += minHeap.top();
            }
            minHeap.pop();
            ++x;
        }
        return ans;
    }
};