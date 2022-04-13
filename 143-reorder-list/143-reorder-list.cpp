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
    void reorderList(ListNode* head) {
        deque<int> d;
        ListNode* curr=head;
        while(curr!=NULL){
            d.push_back(curr->val);
            curr=curr->next;
        }
        int i=0;
        ListNode* curr1=head;
        while(d.empty()==false){
            if(i%2==0){
                curr1->val=d.front();
                d.pop_front();
            } else {
                curr1->val=d.back();
                d.pop_back();
            }
            i++;
            curr1=curr1->next;
        }
        
    }
};