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
    struct comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode* >,comp>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        ListNode* curr=NULL;
        ListNode* res=NULL;
        while(pq.empty()==false){
            ListNode* temp=pq.top();
            pq.pop();
            if(res==NULL){
                curr=res=temp;
            } else {
                res->next=temp;
                res=res->next;
            }
            ListNode* temp2 = temp->next;
            if(temp2!=NULL){
                pq.push(temp2);
            }
        }
        return curr;
        
    }
};