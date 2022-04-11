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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if(head==NULL){
            return res;
        }
        stack<int> s;
        stack<int> st;
        ListNode* curr=head;
        while(curr!=NULL){
            st.push(curr->val);
            curr=curr->next;
        }
        res.push_back(0);
        s.push(st.top());
        st.pop();
        while(st.empty()==false){
            while(s.empty()==false && s.top()<=st.top()){
                s.pop();
            }
            int temp = (s.empty())?0:s.top();
            res.push_back(temp);
            s.push(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};