#include <stdlib.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int lenOfList(struct ListNode* head){
    int len = 0;
    while(head){
        ++len;
        head=head->next;
    }
    return len;
}

int* list2Array(struct ListNode* head, int len){
    int i = 0;
    int* nums = NULL;
    if(len){
        nums = (int*)malloc(sizeof(int)*len);
        while(head){
            *(nums+i) = head->val;
            head=head->next;
            ++i;
        }
    }
    return nums;
}

struct TreeNode* subConvert(int* nums, int start, int size){
    struct TreeNode* root=NULL;
    if(size){
        int mid = start + (size-1)/2;
        root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = *(nums+mid);
        root->left = subConvert(nums,start,mid-start);
        root->right = subConvert(nums,mid+1,size-1-mid+start);
    }
    return root;
}

struct TreeNode* sortedArrayToBST2(int* nums, int numsSize){
    return subConvert(nums,0,numsSize);
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    int len = lenOfList(head);
    int* nums = list2Array(head,len);
    return sortedArrayToBST2(nums,len);
}


int main(void){
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    sortedListToBST(head);

    return 0;
}