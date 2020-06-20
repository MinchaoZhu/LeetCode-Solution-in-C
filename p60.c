#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//https://leetcode.com/problems/permutation-sequence/discuss/697272/C%2B%2B-0ms-solution-by-using-std%3A%3Alist-with-example
// class Solution {
// public:
//     string getPermutation(int n, int k) {
//         vector<int> modular(n+1);
//         modular[0] = 1;
//         for(int i = 1; i<=n; ++i){
//             modular[i] = modular[i-1] * i;
//         }
        
//         list<char> nums; // includes remaining digits
//         for(int i = 1; i<=n; ++i){
//             nums.emplace_back(i + '0');
//         }
        
//         string result = "";
//         int pos;
//         int res = k - 1; 
        
//         for(int i = n-1; i>=0; --i){
//             pos = res / modular[i];
//             res = res % modular[i];
            
//             auto iter = nums.begin();
//             advance(iter, pos);
//             result += *iter;
//             nums.erase(iter);
//         }
        
//         return result;
//     }
// };

int find(bool*flag,int pos,int size){
    for(int i = 0;i<size;++i){
        if(!flag[i])
            --pos;
        if(pos<0)
            return i;
    }
    return size-1;
}

char* getPermutation(int n, int k) {
    bool flag[n];
    int i;
    char * result;
    result = (char*)malloc(sizeof(char)*(n+1));
    for(i = 0;i<n;++i){
        flag[i] = 0;
    }
    int num = 1;
    for(i = 1;i<n;++i){
        num*=i;
    }
    int pos = 0,t = n-1;
    for(i = 0;i<n-1;++i,--t){
        pos = (k-1)/num;
        k -=pos*num;
        num/=t>0?t:1;
        *(result+i) = find(flag,pos,n)+'1';
        flag[*(result+i)-'1'] = 1;
    }
    *(result+i) = find(flag,0,n)+'1';
    *(result+n) = '\0';
    return result;
}


int main(void){
    char* re;
    re = getPermutation(4,9);
    printf("%s",re);


    return 0;
}