#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct flagTable{
    bool flag;
    int add;
    int next;
}flagTable; 

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool cmpNChar(char*s1, char*s2,int N){
    for(int i =0;i<N;++i){
        if(*(s1+i)!=*(s2+i))
            return 1;
    }
    return 0;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    if(s==NULL){
        *returnSize = 0;
        return NULL;
    }
    if(s&&*s=='\0'){
        *returnSize = 0;
        return NULL;
    }
    if(wordsSize == 0)
        return NULL;
    flagTable flag[wordsSize];
    int i,j,wordsLen = 0,index,minAddIndex,minAdd;
    int capacity = 10;
    *returnSize = 0;
    bool failure = 0, isWord = 0;;
    for(i = 0;i<wordsSize;++i){
        flag[i].flag = 0;
        flag[i].add = -1;
        flag[i].next = -1;
    }
    for(i = 0;i<wordsSize-1;++i){
        for(j = i+1;j<wordsSize;++j){
            if(!strcmp(*(words+i),*(words+j))){
                flag[i].next = j;
                break;
            }
        }
    }
    i = 0;
    while(*(*words+i)){
        ++i;
        ++wordsLen;
    }
    int * rT = (int*)malloc(capacity*sizeof(int));
    j = 0;
    for(i = 0;i<wordsLen;++i){
            if(*(s+i)=='\0')
                return rT;    
    }
    while(s&&*s!='\0'){
        isWord = 0;
        for(i = 0;i<wordsSize;++i){
            if(!cmpNChar(s,*(words+i),wordsLen)){
                isWord = 1;
                if(flag[i].flag==0){
                    flag[i].flag = 1;
                    flag[i].add = j;
                    break;
                }
                else{
                    index = i;
                    while(flag[index].next!=-1){
                        index = flag[index].next;
                    }
                    if(flag[index].flag==0){
                        flag[index].flag = 1;
                        flag[index].add = j;
                        break;
                    }
                    else{
                        minAddIndex = index;
                        minAdd = j;
                        flag[index].flag = 1;
                        while(i!=-1){
                            if(flag[i].add<minAdd){
                                minAdd = flag[i].add;
                                minAddIndex = i;
                            }
                            i = flag[i].next;
                        }
                        for(i = 0;i<wordsSize;++i){
                            if(flag[i].add<=minAdd){
                                flag[i].flag = 0;
                                flag[i].add = -1;
                            }
                        }
                        flag[minAddIndex].flag = 1;
                        flag[minAddIndex].add = minAdd;

                        break;
                    }
                }
            }
        }
        if(!isWord){
            for(i = 0;i<wordsSize;++i){
                flag[i].flag = 0;
                flag[i].add = -1;
            }    
            ++s;
            ++j;
            continue;
        }
        failure = 0;
        for(i = 0;i<wordsSize;++i){
            if(flag[i].flag==0){
                failure = 1;
                break;
            }
        }
        if(!failure){
            if(*returnSize>=capacity){
                rT = realloc(rT,2*capacity);
                capacity*=2;
            }
            *(rT+*returnSize) = j-wordsLen*(wordsSize-1);
            *returnSize+=1;
            minAdd = j;
            index = 0;
            for(i = 0;i<wordsSize;++i){
                if(flag[i].add<minAdd){
                    minAdd = flag[i].add;
                    index = i;
                }
            }
            flag[index].flag = 0;
            flag[index].add = -1;
        }

        j += wordsLen;
        s += wordsLen;        
        for(i = 0;i<wordsLen;++i){
            if(*(s+i)=='\0')
                return rT;    
        }
    }
    return rT;
}





int main(void){
    char * s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char * words[4];
    int returnSize=0;
    int * rT;
    words[0] = "aa";
    words[1] = "aa";
    words[2] = "aa";
    words[3] = "aa";
    rT = findSubstring(s,words,4,&returnSize);

    for(int i = 0;i<returnSize;++i){
        printf("%d ",*(rT+i));
    }
    printf("\n");

    return 0;
}
