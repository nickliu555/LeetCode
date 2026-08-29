class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sortedNums(nums);
        std::sort(sortedNums.begin(), sortedNums.end());
        unordered_map<int, int> numToGroupIndex;

        vector<queue<int>> groupIndexToGroupQueue;
        groupIndexToGroupQueue.push_back(queue<int>());
        groupIndexToGroupQueue[0].push(sortedNums[0]);
        numToGroupIndex[sortedNums[0]] = 0;
        for (int i=1; i<sortedNums.size(); ++i) {
            if (sortedNums[i] - groupIndexToGroupQueue.back().back() <= limit) {
                groupIndexToGroupQueue.back().push(sortedNums[i]);
            } else {
                groupIndexToGroupQueue.push_back(queue<int>());
                groupIndexToGroupQueue.back().push(sortedNums[i]);
            }
            numToGroupIndex[sortedNums[i]] = groupIndexToGroupQueue.size()-1;
        }

        vector<int> ans;
        for (int num: nums) {
            int groupIndex = numToGroupIndex[num];
            ans.push_back(groupIndexToGroupQueue[groupIndex].front());
            groupIndexToGroupQueue[groupIndex].pop();
        }
        return ans;
    }
};