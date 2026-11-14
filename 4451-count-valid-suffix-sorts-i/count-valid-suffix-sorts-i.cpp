class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size(), indexLeftEqual = -1, numDiff = 0, ans = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] == target[i]) {
                indexLeftEqual = i;
            } else {
                break;
            }
        }

        unordered_map<int,int> count;
        for (int i=n-1; i>=0; --i) {
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

            if (i > indexLeftEqual+1) {
                continue;
            }
            if (numDiff == 0) {
                ++ans;
            }
        }
        return ans;
    }
};