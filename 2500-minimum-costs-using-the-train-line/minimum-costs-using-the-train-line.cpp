class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        vector<long long> ans;
        long long minRegular = 0, minExpress = expressCost;
        for (int i=0; i<regular.size(); ++i) {
            long long newMinRegular = std::min(minRegular, minExpress) + regular[i];
            long long newMinExpress = std::min(minRegular+expressCost, minExpress) + express[i];
            minRegular = newMinRegular;
            minExpress = newMinExpress;
            ans.push_back(std::min(minRegular, minExpress));
        }
        return ans;
    }
};