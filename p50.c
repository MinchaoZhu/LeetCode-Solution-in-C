#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>



// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(x == 0)
//             return 0;
//         double powValue[32];
//         double tmp = n>0?x:1/x;
//         uint32_t nn = abs(n);
//         for(int i = 0; i<32; ++i) {
//             powValue[i] = tmp;
//             tmp *= tmp;
//         }
        
//         double result = 1;
//         for(int i = 0; i<32; ++i) {
//             result *= (nn&1) ? powValue[i] : 1;
//             nn = nn >> 1;
//         }
        
//         return result;
        
//     }
// };


double myPow(double x, int n) {
    double result = 1.0;
    int exp = 0;
    long nn = n,nnn;
    bool expTable[32] = {0};
    if(n>0){
        while(n>1){
            n = n>>1;
            ++exp;
        }
        n = nn;
        nn = exp;
        while(n>0){
            if(n>=(1<<exp)){
                n = n-(1<<exp);
                expTable[exp] = 1;
            }
            --exp;
        }
        exp = nn;
        double twoPowExp = x;
        for(nn = 0;nn<exp+1;++nn){
            if(expTable[nn]){
                result *= twoPowExp;
            }
            twoPowExp = twoPowExp*twoPowExp;
        }
        return result;
    }
    else if(n<0){
        nn = n;
        nn = -nn;
        nnn = nn;
        while(nn>1){
            nn = nn>>1;
            ++exp;
        }
        nn = nnn;
        nnn = exp;
        while(nn>0){
            if(nn>=UINT32_C(1)<<exp){
                nn = nn-(UINT32_C(1)<<exp);
                expTable[exp] = 1;
            }
            --exp;
        }
        exp = nnn;
        double twoPowExp = x;
        for(nnn = 0;nnn<exp+1;++nnn){
            if(expTable[nnn]){
                result *= twoPowExp;
            }
            twoPowExp = twoPowExp*twoPowExp;
        }
        return 1/result;
    }
    else{
        return 1.0;
    }
}



int main(void){
    double re, re2;
    re = myPow(2.0,-2);
    re2 = pow(2.0, -2);
    printf("%lf\n",re);
    printf("%lf\n",re2);

    return 0;
}