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


struct ListNode* reverseK(struct ListNode* head,struct ListNode **nextTail,int k, int * flag)
{
    int i=0;
    struct ListNode * temp = head->next, *temp1,*temp3 = head;
    if(temp){
         temp1 = temp->next;
    }
    else
    {
        *nextTail = head;
        return NULL;
    }
    
    for(;i<k-1;++i){
        temp->next = head;
        head = temp;
        temp = temp1;
        if(!temp){
            temp3->next = NULL;
            break;
        }
        temp1 = temp->next;
    }
    *nextTail = head;
    if(i<k-2){
        *flag = 0;
        temp3 = head;
        temp = head->next;
        temp1 = temp->next;
        for(i = 0;i<k-1;++i){
            temp->next = head;
            head = temp;
            temp = temp1;
            if(!temp){
                temp3->next = NULL; 
                break;
            }
            temp1 = temp->next;
         }
        *nextTail = head;
         return NULL;
    }
        
    return temp;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode * preHead, * nextHead = head, *nextTail, *temp,*returnHead;
    int flag = 1;
    if(!head)
        return NULL;
    if(k == 1)
        return head;
    preHead = head;    
    temp = nextHead;
    nextHead = reverseK(nextHead,&nextTail,k,&flag);
    if(!flag)
        return preHead;
    preHead->next = nextTail;
    preHead = temp;
    returnHead = nextTail;
    while(nextHead){
        temp = nextHead;
        nextHead = reverseK(nextHead,&nextTail,k,&flag);
        preHead->next = nextTail;
        preHead = temp;
    }
    if(flag){
        preHead->next = NULL;
    }
    return returnHead;
}




int main(void){
    int A[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    struct ListNode * head  = createList(A,12);
    head = reverseKGroup(head,5);
    printList(head);

    return 0;
}