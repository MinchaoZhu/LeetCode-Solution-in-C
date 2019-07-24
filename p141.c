#include <stdbool.h>
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

bool hasCycle(struct ListNode *head) {
    if(head){
        struct ListNode* p1 = head, * p2 = head;
        p2 = p2->next;
        while(p1&&p2){
            if(p1==p2) return 1;
            p1=p1->next;
            p2=p2->next;
            if(p2) p2 = p2->next;
            else return 0;
        } 
    }
    return 0;
}