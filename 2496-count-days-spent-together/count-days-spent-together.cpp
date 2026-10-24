class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int arriveOverlap = std::max(
            convertDateToDays(arriveAlice, daysInMonth), 
            convertDateToDays(arriveBob, daysInMonth));
        int leaveOverlap = std::min(
            convertDateToDays(leaveAlice, daysInMonth), 
            convertDateToDays(leaveBob, daysInMonth));
        return std::max(0, leaveOverlap - arriveOverlap + 1);
    }

    int convertDateToDays(string date, vector<int>& daysInMonth) {
        int month = std::stoi(date.substr(0,2));
        int day = std::stoi(date.substr(3,2));
        int days = day;
        for (int i=0; i<month-1; ++i) {
            days += daysInMonth[i];
        }
        return days;
    } 
};