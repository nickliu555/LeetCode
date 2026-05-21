class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> seenPrefix;
        for (int num: arr1) {
            while (num > 0 && seenPrefix.count(num) == 0) {
                seenPrefix.insert(num);
                num /= 10;
            }
        }
        
        int ans = 0;
        for (int num: arr2) {
            while (num > 0 && seenPrefix.count(num) == 0) {
                num /= 10;
            }

            if (num > 0) {
                ans = std::max(ans, (int)std::to_string(num).length());
            }
        }
        return ans;
    }
};