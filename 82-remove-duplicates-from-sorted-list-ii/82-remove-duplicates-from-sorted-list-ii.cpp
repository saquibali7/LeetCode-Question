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
     ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* curr=head;
        bool flag=false;
        bool flag2=false;
        bool flag3=false;
        int del; 
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val == curr->next->val){
                ListNode* temp = curr->next;
                curr->next=curr->next->next;
                delete temp;
                flag=true;
                flag2=true;
            }
            if(flag && curr->next == NULL){
                flag3=true;
                del=curr->val;
            }
            if(curr->next!=NULL && curr->val != curr->next->val && flag){
                 curr->val=curr->next->val;
                 ListNode* temp = curr->next;
                 curr->next=curr->next->next;
                 delete temp;
                 flag=false;
                 flag2=true;
            }
            if(!flag2){
                curr=curr->next;
                flag2=false;
            }
            if(flag2){
                flag2=false;
            }
        }
         if(flag3){
             if(head->next == NULL){
                 return NULL;
             }
             else {
                 ListNode* curr2 = head;
                 while(curr2->next->next!=NULL){
                     curr2=curr2->next;
                 }
                 delete curr2->next;
                 curr2->next = NULL;
                 return head;
             }
         }
        return head;
        
    }
};