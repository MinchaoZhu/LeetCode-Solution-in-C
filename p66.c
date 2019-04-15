/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    for(int i = digitsSize-1;i>=0;--i){
        digits[i] = digits[i]+carry;
        carry = digits[i]/10;
        digits[i] = digits[i]%10;
        if(!carry)break;
    }
    if(carry){
        int * new = (int*)malloc((digitsSize+1)*sizeof(int));
        new[0] = 1;
        for(int i = 1;i<digitsSize+1;++i){
            new[i] = digits[i-1];
        }
        *returnSize = digitsSize+1;
        return new;
    }
    else{
        *returnSize = digitsSize;
        return digits;
    }
}





int main(void){
    int a[3] = {1,2,3};
    int * new = plusOne(a,3,size);


    return 0;
}