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

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head)return head;
    struct ListNode* cur=head, *preValidNode = head;
    int preVal = head->val;
    if(!(!head||(head->next&&(head->val!=head->next->val||!(head->next))))){
        cur=head;
        while(cur&&((cur->next&&cur->val==cur->next->val))){
            while(cur&&preVal==cur->val){
                cur=cur->next;
            }
            if(cur){
                preVal = cur->val;
            }
        }
        head = cur;
        preValidNode = cur;
    }
    if(!cur)return head;
    preVal = cur->val;
    cur=cur->next;
    while(cur){
        while(cur&&((cur->next&&cur->val==cur->next->val))){
            while(cur&&preVal==cur->val){
                cur=cur->next;
            }
            if(cur)
                preVal = cur->val;
        }
        preValidNode->next = cur;
        preValidNode = cur;
        if(cur)
            cur=cur->next;
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