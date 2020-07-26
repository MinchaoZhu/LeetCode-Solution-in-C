class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        
        int t = 0;
        while(num > 0) {
            t += num % 10;
            num /= 10;
        }
        
        return addDigits(t);
    }
};