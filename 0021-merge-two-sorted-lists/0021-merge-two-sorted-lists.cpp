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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        
        ListNode* head;
        if (t1->val < t2->val) {
            head = t1;
            t1 = t1->next;
        } else {
            head = t2;
            t2 = t2->next;
        }
        
        ListNode* t = head;
        
        while( t1!=NULL && t2!=NULL ) {
            if (t1->val < t2->val) {
                t->next = t1;
                t1 = t1->next;
            } else {
                t->next = t2;
                t2 = t2->next;
            }
            t = t->next;
        }
        
        while( t1!=NULL ) {
            t->next = t1;
            t1 = t1->next;
            t = t->next;
        }
        
        while( t2!=NULL ) {
            t->next = t2;
            t2 = t2->next;
            t = t->next;
        }
        
        return head;
    }
};