class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landStartMin = INT_MAX;
        for (int i=0; i<landStartTime.size(); ++i) {
            landStartMin = std::min(landStartMin, landStartTime[i]+landDuration[i]);
        }
        int ans = INT_MAX;
        for (int i=0; i<waterStartTime.size(); ++i) {
            ans = std::min(ans, std::max(landStartMin, waterStartTime[i]) + waterDuration[i]);
        }
        
        int seaStartMin = INT_MAX;
        for (int i=0; i<waterStartTime.size(); ++i) {
            seaStartMin = std::min(seaStartMin, waterStartTime[i]+waterDuration[i]);
        }
        for (int i=0; i<landStartTime.size(); ++i) {
            ans = std::min(ans, std::max(seaStartMin, landStartTime[i]) + landDuration[i]);
        }

        return ans;
    }   
};