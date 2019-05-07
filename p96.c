#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int numTrees(int n) {
    int result[n+1];
    result[0] = 1;
    result[1] = 1;
    for(int i = 2;i<n+1;++i){
        int sum = 0;
        for(int j = 1;j<i+1;++j){
            sum += result[j-1]*result[i-j];
        }
        result[i] = sum;
    }
    return result[n];
}

int main(void){
    int s;
    s = numTrees(3);
    printf("%d\n",s);




    return 0;
}
