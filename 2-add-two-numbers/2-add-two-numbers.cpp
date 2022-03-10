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
        ListNode* head=NULL;
        ListNode* temp=NULL;
        ListNode* curr;
        int res=0,rem=0,q=0;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        while(curr1!=NULL || curr2!=NULL){
            if(curr1 == NULL){
                res=curr2->val+q;
                curr2=curr2->next;
            }
            else if(curr2 == NULL){
                res=curr1->val+q;
                curr1=curr1->next;
            }
            else {
                res=curr1->val+curr2->val+q;
                curr1=curr1->next;
                curr2=curr2->next;
            }
            if(res >= 10){
                rem = res%10;
                q=res/10;
            }
            else{
                rem=res;
                q=0;
            }
            temp = new ListNode(rem);
            if(head == NULL){
                head=temp;
            }
            else {
                curr=head;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=temp;
            }
        }
        if(head->next==NULL && q!=0){
            head->next=new ListNode(q);
        }
        if(q!=0){
            curr=curr->next;
            curr->next=new ListNode(q);
        }
        return head;
    }
};