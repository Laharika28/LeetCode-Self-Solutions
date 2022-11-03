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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow ){
                break;
            }
        }
        
        if (fast==NULL || fast->next==NULL) {
            return NULL;
        }
        
        if (head!=slow) {
            while (head!=slow) {
                head = head->next;
                slow = slow->next;
            }
        }
        return head;
    }
};