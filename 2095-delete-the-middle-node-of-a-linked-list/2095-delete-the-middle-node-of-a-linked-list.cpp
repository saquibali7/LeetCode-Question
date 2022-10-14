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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            ListNode *temp=head->next;
            head->next=NULL;
            delete temp;
            return head;
            
        }
        ListNode *curr=head;
        ListNode *curr1=head;
        while(curr1!=NULL && curr1->next!=NULL){
            curr=curr->next;
            curr1=curr1->next->next;
        }
        curr->val =curr->next->val;
        curr->next=curr->next->next;
        return head;
    }
};