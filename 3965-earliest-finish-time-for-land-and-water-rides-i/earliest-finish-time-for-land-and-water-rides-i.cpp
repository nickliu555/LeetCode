class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return std::min(calcFinishTime(landStartTime, landDuration, waterStartTime, waterDuration), calcFinishTime(waterStartTime, waterDuration, landStartTime, landDuration));
    }

    int calcFinishTime(vector<int>& startTime1, vector<int>& duration1, vector<int>& startTime2, vector<int>& duration2) {
        int startMin = INT_MAX;
        for (int i=0; i<startTime1.size(); ++i) {
            startMin = std::min(startMin, startTime1[i]+duration1[i]);
        }
        int ans = INT_MAX;
        for (int i=0; i<startTime2.size(); ++i) {
            ans = std::min(ans, std::max(startMin, startTime2[i]) + duration2[i]);
        }
        return ans;
    }   
};