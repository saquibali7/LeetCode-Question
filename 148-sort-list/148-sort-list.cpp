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
  
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        vector<int> res;
        ListNode* curr=head;
        while(curr!=NULL){
            res.push_back(curr->val);;
            curr=curr->next;
        }
        sort(res.begin(),res.end());
        int n=res.size();
        ListNode* head1=NULL;
        ListNode* curr1 = NULL;
        head1 = curr1= new ListNode(res[0]);
        for(int i=1;i<n;i++){
            curr1->next=new ListNode(res[i]);
            curr1=curr1->next;
        }
        return head1;
        
    }
};