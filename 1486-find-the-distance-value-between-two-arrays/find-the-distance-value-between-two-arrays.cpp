class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int num: arr1) {
            int index = findIndexLessOrEqual(arr2, num);
            if (index == -1) {
                if (std::abs(num - arr2.front()) > d) {
                    ++ans;
                }
            } else if (index == arr2.size()-1) {
                if (std::abs(num - arr2.back()) > d) {
                    ++ans;                    
                }
            } else {
                if (std::abs(num - arr2[index]) > d && std::abs(num - arr2[index+1]) > d) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    int findIndexLessOrEqual(vector<int>& arr2, int num) {
        int l = 0, r = arr2.size()-1, res = -1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (arr2[m] <= num) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};