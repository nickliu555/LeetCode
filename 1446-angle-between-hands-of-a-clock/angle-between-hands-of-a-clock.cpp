class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double minuteDegrees = (double)minutes / 60 * 360;
        double hourDegrees = (hour + (double)minutes / 60) / 12 * 360;
        return std::min(std::abs(minuteDegrees - hourDegrees), 360 - std::max(hourDegrees, minuteDegrees) + std::min(hourDegrees, minuteDegrees));
    }
};