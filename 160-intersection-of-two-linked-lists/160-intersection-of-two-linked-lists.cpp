/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        int l1=0,l2=0;
        while(curr1!=NULL){
            l1++;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            l2++;
            curr2=curr2->next;
        }
        ListNode* curr3=headA;
        ListNode* curr4=headB;
        if(l1>l2){
            for(int i=0;i<l1-l2;i++){
                if(curr3==NULL){
                    return NULL;
                }
                curr3=curr3->next;
            }
        }
        if(l2>l1){
            for(int i=0;i<l2-l1;i++){
                if(curr4==NULL){
                    return NULL;
                }
                curr4=curr4->next;
            }
        }
        while(curr3!=NULL && curr4!=NULL){
            if(curr3==curr4){
                return curr3;
            }
            else {
                curr3=curr3->next;
                curr4=curr4->next;
            }
        }
        return NULL;
    }
};