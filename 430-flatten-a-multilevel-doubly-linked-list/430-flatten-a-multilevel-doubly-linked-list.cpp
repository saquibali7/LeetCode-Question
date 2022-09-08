/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }
        stack<Node *> st;
        Node* temp=NULL;
        Node* res=NULL;
        Node* temp1=NULL;
        st.push(head);
        while(!st.empty()){
            head = st.top();
            st.pop();
            if(res==NULL){
                res=temp=head;
                temp1=head;
            } else {
                Node* temp2 = head;
                temp->next = head;
                temp=temp->next;
                temp->prev = temp1;
                temp1=temp2;
            }
            if(head->next!=NULL){
                st.push(head->next);
            }
            if(head->child!=NULL){
                st.push(head->child);
                head->child = NULL;
            }
        }
        return res;
        
    }
};