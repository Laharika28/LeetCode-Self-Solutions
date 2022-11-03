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
    ListNode* middleNode(ListNode* head) {
        int l = 0;
        ListNode* t = head;
        while(t!=NULL){
            l++;
            t=t->next;
        }
        t = head;
        l = (l/2) ;
        while( l>0 ){
            t=t->next;
            l--;
        }
        return t;
    }
};