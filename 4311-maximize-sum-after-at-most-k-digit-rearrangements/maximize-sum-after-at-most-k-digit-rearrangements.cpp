class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long ans = 0;
        std::priority_queue<int, vector<int>, greater<>> minHeap;
        for (int num: nums) {
            ans += num;
            string rearrangedStr = std::to_string(num);
            std::sort(rearrangedStr.rbegin(), rearrangedStr.rend());
            int rearrangedNum = std::stoi(rearrangedStr);
            int increase = rearrangedNum-num;
            minHeap.push(increase);
            ans += increase;
            if (minHeap.size() > k) {
                ans -= minHeap.top();
                minHeap.pop();
            }
        }
        return ans;
    }
};