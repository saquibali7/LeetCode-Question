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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr=head->next;
        while(curr!=NULL){
            ListNode *curr1=head;
            while(curr1->val < curr->val && curr1!=NULL){
                curr1=curr1->next;
            }
            int prev = curr1->val;
            curr1->val=curr->val;
            curr1=curr1->next;
            while(curr1!=curr->next && curr1!=NULL){
                int temp=curr1->val;
                curr1->val=prev;
                prev=temp;
                curr1=curr1->next;
            }
            curr=curr->next;
        }
        return head;
        
    }
};