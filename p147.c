#include <stdlib.h>
#include <stdio.h>
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

struct ListNode* insertionSortList(struct ListNode* head){
    if(head){
        struct ListNode* now = head, *newHead = head, *nextNode = now->next, *preNode = NULL, *cur, *preCur;
        while(now){
            cur = newHead;
            while(cur!=now){
                if(cur->val>now->val){
                    preNode->next = nextNode;
                    if(cur==newHead){
                        newHead = now;
                        now->next = cur;
                    }
                    else{
                        now->next = cur;
                        preCur->next = now;
                    }
                    break;
                }
                else {
                    preCur = cur;
                    cur = cur->next;
                }
            }
            if(cur==now)preNode = now;
            now = nextNode;
            nextNode = now?now->next:now;
        }
        return newHead;
    }
    else return head;
}

void printList(struct ListNode* head){
    while(head){
        printf("%d\n",head->val);
        head = head->next;
    }

}

int main(void){
    struct ListNode* head, *n0,*n1,*n2,*n3;
    n0 = malloc(sizeof(struct ListNode));
    n1 = malloc(sizeof(struct ListNode));
    n2 = malloc(sizeof(struct ListNode));
    n3 = malloc(sizeof(struct ListNode));
    n0->val = 4;
    n1->val = 2;
    n2->val = 1;
    n3->val = 3;
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;
    head = n0;
    printList(head);
    head = insertionSortList(head);   
    printList(head);

}