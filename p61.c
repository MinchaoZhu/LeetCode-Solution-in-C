#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* newHead = head, *temp = head,*tail,*newTail;
    int size = 0,i =0;
    while(temp){
        temp = temp->next;
        ++size;
    }
    if(size==0)return head;
    k = k%size;
    if(k==0)return head;
    temp = head;
    for(i = 0;i<k;++i){
        temp = temp->next;
    }
    while(temp){
        tail = temp;
        temp = temp->next;
        newTail = newHead;
        newHead = newHead->next;
    }
    tail->next = head;
    newTail->next = NULL;
    return newHead;
}


int main(void){



    return 0;
}