/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        ListNode* t1 = h1;
        ListNode* t2 = h2;
        
        while (t1!=NULL && t2!=NULL && t1->next!=NULL && t2->next!=NULL) {
            t1->next = t2->next;
            t1=t1->next;
            t2->next = t1->next;
            t2=t2->next;
        }
        
        t1->next = h2;
        return h1;
    }
};