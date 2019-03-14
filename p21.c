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
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * lNode;
    struct ListNode * returnNode = NULL;
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    if(l1->val<l2->val){
        returnNode = l1;
        lNode = l1;
        l1 = l1->next;
    }
    else{
        returnNode = l2;
        lNode = l2;
        l2 = l2->next;
    }
    while(l1&&l2){
        if(l1->val<l2->val){
            lNode->next = l1;
            lNode = l1;
            l1 = l1->next;
        }
        else{
            lNode->next = l2;
            lNode = l2;
            l2 = l2->next;
        } 
    }
    if(!l1)
        lNode->next = l2;
    else
        lNode -> next = l1;
    return returnNode;


}






int main(void){




    return 0;
}