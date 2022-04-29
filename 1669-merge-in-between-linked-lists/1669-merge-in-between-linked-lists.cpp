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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*curr1=list1;
        ListNode* curr2=list1;
        for(int i=0;i<a-1;i++){
            curr1=curr1->next;
        }
        for(int i=0;i<=b;i++){
            curr2=curr2->next;
        }
        curr1->next=list2;
        ListNode* curr3=list2;
        while(curr3!=NULL && curr3->next!=NULL){
            curr3=curr3->next;
        }
        curr3->next=curr2;
        return list1;
        
    }
};