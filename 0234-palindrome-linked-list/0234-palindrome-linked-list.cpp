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
    int length (ListNode* head) {
        int cnt=0;
        ListNode* temp = head;
        while ( temp!=NULL ) {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    
    ListNode* reverse (ListNode* head) {
        ListNode * prev=NULL,* nxt,* curr=head;
        
        while (curr!=NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    bool isPali ( ListNode* h1, ListNode* h2 ) {
        
        while (h1!=NULL && h2!=NULL) {
            if (h1->val != h2->val) {
                return false;
            }
            h1=h1->next;
            h2=h2->next;
        }
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        int l = length (head);
        
        if (l<2) {
           return true; 
        } 
        if ( l==2 ) {
            return (head->val == head->next->val);
        }
        
        int n,m;
        if (l%2 == 0) {
            n = l/2;
            m = l/2;
        } else {
            n = l/2;
            m = l/2 + 1;
        }
        
        ListNode* h1 = head;
        ListNode* h2 = head;
        
        while ( m > 2) {
            h2=h2->next;
            h1=h1->next;
            m--;
        }
        
        if (l%2 == 0) {
            h2=h2->next->next;
            h1->next->next=NULL;
        } else {
            h2=h2->next;
            h1->next=NULL;
        }
        
        h1 = head;
        h2 = reverse(h2);
        
        return isPali(h1,h2);
        
    }
};