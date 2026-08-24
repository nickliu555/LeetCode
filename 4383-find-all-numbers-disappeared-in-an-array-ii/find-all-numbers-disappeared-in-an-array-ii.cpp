class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int currRange = lower;
        for (int num: nums) {
            if (currRange > upper) break;
            if (num == currRange) {
                ++currRange;
            } else if (num > currRange) {
                ans.push_back({currRange, std::min(num-1, upper)});
                currRange = num + 1;
            }
        }
        if (currRange <= upper) {
            ans.push_back({currRange, upper});
        }
        return ans;
    }
};