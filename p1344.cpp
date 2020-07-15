class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a =  abs(30.0 * (hour%12) + 0.5 * minutes - 6.0 * minutes);
        return min(a, 360 - a);
    }
};