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

struct ListNode* mergeSortedList(struct ListNode* head0, struct ListNode* head1){
    struct ListNode* newHead, *newTail;
    if(!head0)return head1;
    if(!head1)return head0;
    if(head0->val<head1->val){
        newHead = newTail = head0;
        head0 = head0->next;
    }
    else{
        newHead = newTail = head1;
        head1 = head1->next;
    }
    while(head0&&head1){
        if(head0->val<head1->val){
            newTail->next = head0;
            newTail = head0;
            head0 = head0->next;
        }
        else{
            newTail->next = head1;
            newTail = head1;
            head1 = head1->next;
        }        
    }
    if(head0)newTail->next = head0;
    else newTail ->next = head1;
    return newHead;
}

struct ListNode* sortList(struct ListNode* head){
    if(head){
        if(head->next){
            struct ListNode* begin0 = head,*begin1 = head,*temp = head, *pre=NULL, *newHead;
            while(temp){
                pre = begin1;
                begin1=begin1->next;
                temp = temp->next;
                if(temp) temp = temp->next;
            }
            pre->next = NULL;
            begin0 = sortList(begin0);
            begin1 = sortList(begin1);
            newHead = mergeSortedList(begin0,begin1);
            return newHead;
        }
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
    puts("\n");
    head = sortList(head);   
    printList(head);

}