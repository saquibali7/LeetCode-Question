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
    bool hasCycle(ListNode *head) {
        ListNode* curr;
        curr=head;
        ListNode* temp=head;
        while(curr!=NULL){
            if(curr->next==NULL){
                return false;
            }
            if(curr->next == temp){
                return true;
            }
            ListNode* new_head = curr->next;
            curr->next=temp;
            curr=new_head;
        }
        return false;
    }
};