#include <stdio.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * createList(int arr[],int size){
    struct ListNode * head = NULL,*temp,*temp1;
    if(size == 0)  
        return 0;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    temp = head;
    for(int i = 1;i<size;++i){
        temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp1 -> val = arr[i];
        temp1->next = NULL;
        temp->next = temp1;
        temp = temp1;
    }
    return head;
}

void printList(struct ListNode * head){
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    return;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* left = head,*right;
    while(left){
        right = left;
        while(right&&right->val==left->val){
            right=right->next;
        }
        left->next = right;
        left = right;
    }
    return head;
}

int main(void){
    int A[8] = {1,1,2,3,3,4,4,5};
    struct ListNode * head;
    head = createList(A,8);
    head = deleteDuplicates(head);
    printList(head);
    return 0;
}