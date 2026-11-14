class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size(), leftSideAllEqualIndex = -1;
        for (int i=0; i<n; ++i) {
            if (nums[i] == target[i]) {
                leftSideAllEqualIndex = i;
            } else {
                break;
            }
        }

        int numDiff = 0, ans = 0;
        unordered_map<int,int> count;
        for (int i=n-1; i>=0; --i) {
            // target from i...n-1 is not non-decreasing, so never will be a match anymore
            if ((i < n-1 && target[i] < target[i+1])) {
                return ans;
            }

            ++count[nums[i]];
            if (count[nums[i]] == 1) {
                ++numDiff;
            } else if (count[nums[i]] == 0) {
                --numDiff;
            }

            --count[target[i]];
            if (count[target[i]] == -1) {
                ++numDiff;
            } else if (count[target[i]] == 0) {
                --numDiff;
            }

            // if 0...i-1 for nums and target do not match
            if (i > leftSideAllEqualIndex+1) {
                continue;
            }
            if (numDiff == 0) {
                ++ans;
            }
        }
        return ans;
    }
};