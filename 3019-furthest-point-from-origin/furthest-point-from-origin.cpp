class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftTotal = 0, rightTotal = 0, blankTotal = 0;
        for (char move: moves) {
            if (move == 'L') {
                ++leftTotal;
            } else if (move == 'R') {
                ++rightTotal;
            } else {
                ++blankTotal;
            }
        }
        return blankTotal + std::max(leftTotal, rightTotal) - std::min(leftTotal, rightTotal);
    }
};