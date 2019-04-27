#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n)return head;
    struct ListNode* newHead, *leftTail = head, *temp = head;
    struct ListNode* midHead, *midTail;
    struct ListNode* temp1,*temp3;
    int i;
    for(i = 2;i<m;++i){
        leftTail = leftTail->next;
        temp = temp->next;
    }
    midTail = temp->next;
    temp1 = midTail;
    temp = midTail->next;++i;
    if(temp==NULL){temp1->next = head;head->next = NULL;return temp1;}
    temp3 = temp->next;
    while(i<n+1){
        temp->next = temp1;
        temp1 = temp;
        temp = temp3;
        if(temp3)
            temp3 = temp3->next;
        ++i;
    }
    if(m>1){
        newHead = head;
        leftTail->next = temp1;
        midTail->next = temp;
    }
    else{
        head->next->next = head;
        newHead = temp1;
        head->next = temp;
    }
    return newHead;
}

int main(void){
    int A[2] = {3,5};
    struct ListNode* head;
    head = createList(A,2);
    head = reverseBetween(head,1,2);
    printList(head);
    return 0;
}