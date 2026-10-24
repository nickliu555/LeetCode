class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefixSumDaysInMonth {0};
        for (int i=0; i<daysInMonth.size(); ++i) {
            prefixSumDaysInMonth.push_back(daysInMonth[i] + prefixSumDaysInMonth.back());
        }
        
        int arriveOverlap = std::max(
            convertDateToDays(arriveAlice, prefixSumDaysInMonth), 
            convertDateToDays(arriveBob, prefixSumDaysInMonth));
        int leaveOverlap = std::min(
            convertDateToDays(leaveAlice, prefixSumDaysInMonth), 
            convertDateToDays(leaveBob, prefixSumDaysInMonth));
        return std::max(0, leaveOverlap - arriveOverlap + 1);
    }

    int convertDateToDays(string date, vector<int>& prefixSumDaysInMonth) {
        int month = std::stoi(date.substr(0,2));
        int day = std::stoi(date.substr(3,2));
        return prefixSumDaysInMonth[month-1] + day;
    } 
};