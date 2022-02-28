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
    void swap(int *a, int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        ListNode* curr1=head;
        ListNode* curr2=head;
        for(int i=0;i<k-1;i++){
            curr1=curr1->next;
        }
        for(int i=0;i<count-k;i++){
            curr2=curr2->next;
        }
        swap(&curr1->val,&curr2->val);
        return head;
        
    }
};