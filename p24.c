#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };
 */

struct ListNode {
    int val;
    struct ListNode *next;
 }*list, ListNode;

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

struct ListNode* swapPairs(struct ListNode* head) {
    if(!head)
        return NULL;
    struct ListNode* temp = head,*temp1 = head->next,*temp2;
    bool flag = 0;
    if(temp1){
        head = temp1;
        temp ->next = temp1->next;
        temp1->next = temp;
        temp1 = temp;
    }
    else
        return head;
    
    while(1){
        temp = temp1->next;
        if(!temp)
            return head;
        if(temp->next==NULL)
            return head;
        else{
            temp1->next = temp->next;
            temp->next = (temp->next)->next;
            (temp1->next)->next = temp;
            temp1 = temp;
        }
    }
}


int main(void){
    int a[3] = {1,2,3};
    
    struct ListNode * list = createList(a,3);
    list = swapPairs(NULL);
    printList(list);
    return 0;
}