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
        ListNode* curr1 = l1;
        ListNode* prev1 = NULL;
        while(curr1!=NULL){
            ListNode* temp=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=temp;
        }
        ListNode* curr2 = l2;
        ListNode* prev2 = NULL;
        while(curr2!=NULL){
            ListNode* temp=curr2->next;
            curr2->next=prev2;
            prev2=curr2;
            curr2=temp;
        }
        int rem=0,sum=0;
        ListNode* curr3 = prev1;
        ListNode* curr4 = prev2;
        ListNode* res=NULL;
        ListNode* curr5=NULL;
        while(curr3!=NULL || curr4!=NULL){
            if(curr3!=NULL && curr4!= NULL){
                sum = curr3->val + curr4->val + rem;
            } else if(curr3!=NULL && curr4==NULL){
                 sum = curr3->val + rem;
            } else {
                 sum = curr4->val + rem;
            }
            if(sum >= 10){
                rem=1;
                sum = sum%10;
            } else {
                rem=0;
            }
            if(res==NULL){
                res=curr5 =new ListNode(sum);
            }else {
                ListNode* temp = new ListNode(sum);
                temp->next=curr5;
                curr5=temp;
            }
            if(curr3!=NULL){
                curr3 = curr3->next;
            }
            if(curr4!=NULL){
                curr4 = curr4->next;
            }
        }
        if(rem==1){
            ListNode* temp = new ListNode(rem);
            temp->next=curr5;
            curr5=temp;
        }
        return curr5;
        
    }
};