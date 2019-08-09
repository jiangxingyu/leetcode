/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * lN = head;
        ListNode * p = head;
        for (int i = 0; i<n; i++) {
            p = p->next;
        }
        if(p == NULL) {
            return lN->next;
        }
        while (p->next != NULL) {
            p = p->next;
            lN = lN->next;
        }
        lN->next = lN->next->next;
        return head;
    }
};