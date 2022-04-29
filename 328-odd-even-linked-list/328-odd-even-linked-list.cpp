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
    
    ListNode* oddEvenList(ListNode* head) {
        vector<int> temp;
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL){
            temp.push_back(curr->val);
            curr=curr->next;
        }
        count=0;
        curr=head;
        while(count<temp.size() && curr!=NULL){
            curr->val=temp[count];
            count=count+2;
            curr=curr->next;
        }
        count=1;
        while(count<temp.size() && curr!=NULL){
            curr->val=temp[count];
            count=count+2;
            curr=curr->next;
        }
        return head;
    }
};