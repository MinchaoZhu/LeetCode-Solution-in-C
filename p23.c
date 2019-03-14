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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0)
        return NULL;
    if(listsSize == 1)
        return *lists;
    int isNotBlank[listsSize];
    int i = 0, size = 0,k;
    int valTemp, index;
    struct ListNode* list[listsSize];
    struct ListNode * pTemp = (struct ListNode *)malloc(sizeof(struct ListNode)),*head = pTemp;
    head -> next = NULL;
    head -> val = 0;
    for(i = 0;i<listsSize;++i){
        if(*(lists+i)!=NULL){
            list[i] = *(lists+i);
            isNotBlank[size] = i;
            ++size;
        }
    }
    if(size==0)
        return NULL;
    while(size>1){
        valTemp = list[isNotBlank[0]]->val;
        index = isNotBlank[0];
        k = 0;
        for(i = 1;i<size;++i){
            if(valTemp>list[isNotBlank[i]]->val){
                valTemp = list[isNotBlank[i]]->val;
                index = isNotBlank[i];
                k = i;
            }
        }
        pTemp->next = list[index];
        pTemp = pTemp->next;
        list[index] = list[index]->next;
        if(list[index]==NULL){
            isNotBlank[k] = isNotBlank[size-1];
            --size;
        }
    }

    pTemp->next = list[isNotBlank[0]];

    return head->next;
}


int main(void){
    int a[3] = {1,4,5};
    int b[3] = {1,3,4};
    int c[2] = {2,6};
    //struct ListNode * lists[3],*returnList;
    //lists[0] = createList(a,3);
    //lists[1] = createList(b,3);
    //lists[2] = createList(c,2);
    

    struct ListNode * lists[2],*returnList;
    lists[0] = NULL;
    lists[1] = NULL;
    returnList = mergeKLists(lists,2);
    printList(returnList);

    return 0;
}