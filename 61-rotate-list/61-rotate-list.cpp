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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int n=0;
        ListNode* curr1=head;
        while(curr1!=NULL){
            n++;
            curr1=curr1->next;
        }
        if(k>n){
            int temp=k/n;
            k = k -(temp*n);
        }
        for(int i=0;i<k;i++){
            ListNode* curr = head;
            while(curr->next->next!=NULL){
                curr=curr->next;
            }
            ListNode* temp = curr->next;
            curr->next=NULL;
            temp->next = head;
            head=temp;
        }
        return head;
        
    }
};