class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr, *cur = head;
        ListNode* newHead = nullptr;
        while(cur) { // one pass scan
            if(cur -> val == val) {
                if(prev)
                    prev -> next = cur -> next;
            }
            else {
                prev = cur;
            }
            cur = cur -> next;
            newHead = newHead?newHead:prev; // if head is empty, previous node should be new head
        }
        return newHead;
    }
};