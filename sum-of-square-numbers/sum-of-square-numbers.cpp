class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0)
            return true;
        for(int i = 0; i<sqrt(c); i++) {
            long int a2 = i*i;
            long int b2 = c - i*i;
            long int b = sqrt(b2);
            if(b2 == b*b)
                return true;
        }
        return false;
    }
};