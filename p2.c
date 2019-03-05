/*
 * @Author: Minchao Zhu 
 * @Date: 2019-03-04 16:33:16 
 * @Last Modified by: Minchao Zhu
 * @Last Modified time: 2019-03-04 17:38:44
 */


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

struct ListNode * newNode(int sum,struct ListNode * presentNode){
    struct ListNode * new_Node = malloc(sizeof(struct ListNode));
    presentNode -> next = new_Node;
    new_Node -> val = sum;
    new_Node -> next = NULL;
    return new_Node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * result = (struct ListNode *)malloc(sizeof(struct ListNode)),  * presentNode = result;
    int carryDigit = 0;
    int l1num = l1->val, l2num = l2->val, sum = l1num+l2num;
    if(sum<10)
        result->val = sum;
    else{
        result ->val = sum-10;
        carryDigit = 1;
    }
    result -> next = NULL;
    l1 = l1->next;
    l2 = l2->next;

    while(l1 && l2){
        sum = l1->val+l2->val+carryDigit;
        l1 = l1->next;
        l2 = l2->next;
        if(sum<10)
            carryDigit = 0;
        else{
            carryDigit = 1;
            sum = sum - 10;
        }
        presentNode = newNode(sum,presentNode);
    }
    if(l1||l2){
        if(l1){
            while(l1){
                sum = carryDigit + l1->val;
                if(sum<10)
                    carryDigit = 0;
                else{
                    carryDigit = 1;
                    sum = sum - 10;
                }
                presentNode = newNode(sum,presentNode);
                l1 = l1->next;
            }
        }
        if(l2){
            while(l2){
                sum = carryDigit + l2->val;
                if(sum<10)
                    carryDigit = 0;
                else{
                    carryDigit = 1;
                    sum = sum - 10;
                }
                presentNode = newNode(sum,presentNode);
                l2 = l2->next;
            }
        }

    }
    if(carryDigit == 1){
        presentNode = newNode(1,presentNode);
    }

    return result;
}


void printList(struct ListNode * list){
    do{
        printf("%d\n",list->val);
    }
    while(list = list->next);
    


    return;
}

int main(void){
    struct ListNode * a,*b,*c,*d,*e,*f,*result;
    a = (struct ListNode *)malloc(sizeof(struct ListNode));
    b = (struct ListNode *)malloc(sizeof(struct ListNode));
    c = (struct ListNode *)malloc(sizeof(struct ListNode));
    d = (struct ListNode *)malloc(sizeof(struct ListNode));
    e = (struct ListNode *)malloc(sizeof(struct ListNode));
    f = (struct ListNode *)malloc(sizeof(struct ListNode));
    a->val = 0;
    b->val = 9;
    c->val = 9;
    d->val = 0;
    e->val = 6;
    f->val = 4;
    a->next = NULL;
    b->next = c;
    c->next = NULL;
    d->next = NULL;
    e->next = f;
    f->next = NULL;
    result = addTwoNumbers(a,d);
    printList(result);
    return 0;
}
