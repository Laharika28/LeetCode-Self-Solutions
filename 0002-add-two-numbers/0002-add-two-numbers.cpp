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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        int carry = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* h = head;
        while(h1!=NULL && h2!=NULL){
            int x = h1->val + h2->val + carry;
            h->next = new ListNode(x%10);
            carry = x/10;
            h=h->next;
            h1=h1->next;
            h2=h2->next;
        }
        
        while(h1!=NULL){
            int x = h1->val + carry;
            h->next = new ListNode(x%10);
            carry = x/10;
            h=h->next;
            h1=h1->next;
        }
        
        while(h2!=NULL){
            int x = h2->val + carry;
            h->next = new ListNode(x%10);
            carry = x/10;
            h=h->next;
            h2=h2->next;
        }
        
        while(carry>0){
            h->next = new ListNode(carry%10);
            carry/=10;
        }
        
        return head->next;
    }
};