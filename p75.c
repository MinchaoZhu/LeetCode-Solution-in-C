#include <stdio.h>
void swap(int * pa, int * pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void sortColors(int* nums, int numsSize) {
    int tail0 = 0, head2 = numsSize-1;
    int i = 0;
    /**
     * tail0 is the next position for color 0;
     * value before position tail0 is 0;
     * head2 is the previous position for first posiiton of color 2;
     * value after head2 is 2;
     * **/
    while(i<=head2){
        if(nums[i]==0){
            swap(nums+i,nums+tail0);
            ++tail0;
            /**
             * if i>tail0 and changed color is not 1;
             * continue swaping until color is 1
             * */
            while(i!=tail0-1&&nums[i]!=1){
                if(nums[i]==0){
                    swap(nums+i,nums+tail0);
                    ++tail0;
                }
                else if(nums[i]==2){
                    swap(nums+i,nums+head2);
                    --head2;
                }
            }
        }
        else if(nums[i]==2){
            swap(nums+i,nums+head2);
            --head2;
            while(i<=head2&&i!=tail0-1&&nums[i]!=1){
                if(nums[i]==0){
                    swap(nums+i,nums+tail0);
                    ++tail0;
                }
                else if(nums[i]==2){
                    swap(nums+i,nums+head2);
                    --head2;
                }
            }
        }
        ++i;
    }
}

int main(void){
    int l = 6;
    int A[6] = {1,1,2,2,0,0};
    sortColors(A,6);
    for(int i =0;i<6;++i){
        printf("%d ", A[i]);
    }
    printf("\n");


    return 0;
}