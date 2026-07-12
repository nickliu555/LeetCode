class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        vector<int> ans(n);
        vector<pair<int,int>> sortedArr;
        for (int i=0; i<n; ++i) {
            sortedArr.push_back({arr[i], i});
        }
        std::sort(sortedArr.begin(), sortedArr.end());

        ans[sortedArr[0].second] = 1;
        int rank = 1;
        for (int i=1; i<n; ++i) {
            if (sortedArr[i].first > sortedArr[i-1].first) {
                ++rank;
            }
            ans[sortedArr[i].second] = rank;
        }
        return ans;
    }
};