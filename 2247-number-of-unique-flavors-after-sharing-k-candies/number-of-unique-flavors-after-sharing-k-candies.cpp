class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> count;
        for (int candy: candies) ++count[candy];
        if (k == 0) return count.size();
        int ans = 0;
        for (int l=0, r=0; r<candies.size(); ++r) {
            --count[candies[r]];
            if (count[candies[r]] == 0) {
                count.erase(candies[r]);
            }
            if (r - l + 1 == k) {
                ans = std::max(ans, (int)count.size());
                ++count[candies[l]];
                ++l;
            }
        }
        return ans;
    }
};