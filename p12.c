#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * intToRoman(int num){
    char * roman = malloc(16*sizeof(char)),* temp = roman;
    while(num>=1000){
        *(temp++) = 'M';
        num -=1000;
    }
    if(num>=900){
        *(temp++) = 'C';
        *(temp++) = 'M';
        num -= 900;
    }
    if(num>=500){
        *(temp++) = 'D';
        num -= 500;
    }
    if(num>=400){
        *(temp++) = 'C';
        *(temp++) = 'D';
        num -= 400;
    }
    while(num>=100){
        *(temp++) = 'C';
        num -=100;
    }
    if(num>=90){
        *(temp++) = 'X';
        *(temp++) = 'C';
        num -= 90;
    }
    if(num>=50){
        *(temp++) = 'L';
        num -= 50;
    }
    if(num>=40){
        *(temp++) = 'X';
        *(temp++) = 'L';
        num -= 40;
    }
    while(num>=10){
        *(temp++) = 'X';
        num -= 10;
    }
    if(num>=9){
        *(temp++) = 'I';
        *(temp++) = 'X';
        num -= 9;
    }
    if(num>=5){
        *(temp++) = 'V';
        num -= 5;
    }
    if(num>=4){
        *(temp++) = 'I';
        *(temp++) = 'V';
        num -= 4;
    }
    while(num>=1){
        *(temp++) = 'I';
        num -= 1;
    }
    *temp = '\0';
    return roman;
}

int main(void){
    int max = 0,len= 0,maxNum;
    char * temp = NULL;
    for(int i = 1;i<4000;i++){
        len = strlen(intToRoman(i));
        max = len>max?len:max;
        if(len==max)
            maxNum = i;
    }
    printf("%d. maxNum is %d.\n",max,maxNum);
    printf("The roman expression of 3888 is %s.\n",intToRoman(3888));

    return 0;
}