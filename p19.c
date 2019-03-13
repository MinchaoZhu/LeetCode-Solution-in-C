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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i;
    struct ListNode * cur0 = head, *cur1 = head;
    for(i = 0; i<n;++i){
        cur0 = cur0->next;
    }
    if(cur0 == 0)
        return head->next;
    while(cur0->next){
        cur1 = cur1->next;
        cur0 = cur0->next;
    }
    cur1->next = (cur1->next)->next;

    
    return head;
}
















int main(void){
    struct ListNode * head;
    int arr[2] = {1,2};
    head = createList(arr,2);
    head = removeNthFromEnd(head,2);
    printList(head);

    return 0;
}