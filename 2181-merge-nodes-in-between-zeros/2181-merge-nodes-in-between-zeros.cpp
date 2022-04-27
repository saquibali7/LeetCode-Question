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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode* res=NULL;
        ListNode* temp=NULL;
        while(head!=NULL){
            if(head->val==0 && sum!=0){
                if(res==NULL){
                    res= temp = new ListNode(sum);
                } else {
                    temp->next =new ListNode(sum);
                    temp=temp->next;
                }
                sum=0;
            }
            else if(head->val!=0) {
                sum+=head->val;
            }
            else if(head->val==0){
                sum=0;
            }
            head=head->next;
        }
        if(sum!=0){
            temp->next =new ListNode(sum);
            temp=temp->next;
        }
        return res;
        
    }
};