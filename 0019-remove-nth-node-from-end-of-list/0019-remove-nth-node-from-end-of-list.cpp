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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( n==0 ) {
            return head;
        }
        int l = 0;
        
        ListNode* temp = head;
        while (temp!=NULL) {
            l++;
            temp=temp->next;
        }
        
        n = l-n;
        if (n==0) {
            return head->next;
        }
        temp = head;
        l = 0;
        while (temp!=NULL) {
            l++;
            if (l==n) {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};