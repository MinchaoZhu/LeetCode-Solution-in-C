#include <stdio.h>
#include <stdbool.h>
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

int listlen(struct ListNode* head){
    int len = 0;
    while(head){
        head = head->next;
        ++len;
    }
    return len;
}

struct ListNode* listnode(struct ListNode* head, int n){
    int i = 0;
    for(;i<n;++i){
        head = head->next;
    }
    return head;
}

struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !(head->next))
        return head;
    struct ListNode * originalNext = head -> next, * nowNode = head, * newNext = NULL;

    nowNode -> next = newNext;
    newNext = nowNode; 
    nowNode = originalNext;
    originalNext = originalNext -> next;

    while(nowNode->next)
    {
        nowNode -> next = newNext;
        newNext = nowNode; 
        nowNode = originalNext;
        originalNext = originalNext -> next;
    }
    
    nowNode -> next = newNext;
    return nowNode;
}

void reorderList(struct ListNode* head){
    if(head){
        int len = listlen(head);
        int len2 = len/2, len1 = len-len2;
        struct ListNode* list1 = head, *list2 = listnode(head,len1),*newList = head;
        list2 = reverseList(list2);
        //printf("len = %d, len1 = %d, len2 = %d\n",len,len1,len2 );
        //printList(list2);

 
        bool flag = 1;
        for(int i = 1;i<len;++i){
            if(flag==0){
                list2 = list2->next;
                head->next = list1; 
            }
            else{
                list1 = list1->next;
                head->next = list2;
            }
            head = head->next;
            flag = !flag;
        }
        head->next = NULL;
        head = newList;
    }
}

int main(void){
    struct ListNode* head;
    int arr[5] = {1,2,3,4,5};
    head = createList(arr,5);
    reorderList(head);
    printList(head);
}