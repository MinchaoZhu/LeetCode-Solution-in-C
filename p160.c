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

int lenOfList(struct ListNode* head){
    int len = 0;
    while(head){
        ++len;
        head = head->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = lenOfList(headA), lenB = lenOfList(headB);
    if(lenA>lenB){ 
        int temp = lenA;
        struct ListNode* tempNode = headA;
        headA = headB; lenA = lenB;
        headB = tempNode; lenB = temp;
    }
    for(int i = 0;i<lenB-lenA;++i) headB = headB->next;
    if(headA==headB) return headA;
    for(int i = 0;i<lenA;++i){
        headA = headA->next;
        headB = headB->next;
        if(headA==headB) return headA;
    }
    return NULL;
}