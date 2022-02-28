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
        ListNode* curr1=head;
        ListNode* curr2=head;
        for(int i=0;i<k-1;i++){
            curr1=curr1->next;
        }
        ListNode* curr3=curr1;
        while(curr3->next!=NULL){
            curr3=curr3->next;
            curr2=curr2->next;
        }
        swap(&curr1->val,&curr2->val);
        return head;
        
    }
};