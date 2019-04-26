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

struct ListNode* partition(struct ListNode* head, int x){
    if(!head)return head;
    struct ListNode* temp= head,* head2 = head,*tail = NULL,*tail2 = NULL;
    bool findHead1 = 0, findHead2 = 0;
    while(temp&&(!findHead1||!findHead2)){
        if(temp->val<x){
            if(!findHead1){
                head = temp;
                tail = temp;
                findHead1 = 1;
            }
            else{
                tail = temp;
            }
        }
        else{
            if(!findHead2){
                head2 = temp;
                tail2 = temp;
                findHead2 = 1;
            }
            else{
                tail2 = temp;
            }
        }
        temp = temp->next;
    }
    while(temp){
        if(temp->val<x){
            tail->next = temp;
            tail = temp;
        }
        else{
            tail2->next = temp;
            tail2 = temp;
        }
        temp = temp->next;
    }
    if(!tail)return head2;
    if(!tail2)return head;
    tail->next = head2;
    tail2->next = NULL;
    return head;
}


int main(void){
    int A[6] = {1,4,3,2,5,2};
    struct ListNode * head;
    head = createList(A,6);
    printList(head);
    head = partition(head,6);
    printList(head);
    return 0;
}