/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <set>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::set<ListNode*> nodeSet;
        while(head){
            if(nodeSet.find(head)==nodeSet.end()){
                nodeSet.insert(head);
                head = head->next;
            }
            else return head;
        }
        return NULL;
    }
};