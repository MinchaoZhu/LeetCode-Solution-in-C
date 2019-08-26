#include <stdbool.h>
#include <string.h>


bool isOneEditDistance(char * s, char * t){
    int lens = strlen(s), lent = strlen(t);
    int temp = lens-lent;char* tempS;
    if(temp>1||temp<-1) return 0;
    if(lens==lent){
        bool flag = 0;
        for(int i = 0;i<lens;++i){
            if(s[i]!=t[i]){
                if(!flag) flag = 1;
                else return 0;
            }
        }
        return flag;
    }
    else{
        if(lens>lent){
            tempS = s;temp = lens;
            s = t;lens = lent;
            t = tempS;lent = temp;
        }
        bool flag = 0;
        for(int i = 0,j = 0;i<lens;++i,++j){
            if(s[i]!=t[j]){
                if(!flag){
                    flag=1;
                    --i;
                }
                else return 0;
            }
        }
        return 1;
    }
}

