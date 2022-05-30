/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL ){
            return NULL;
        }
        if(head->next==NULL && head->random==NULL){
            Node* temp=new Node(head->val);
            return temp;
        }
        if(head->next==NULL && head->random!=NULL){
            Node* temp=new Node(head->val);
            temp->random = temp;
            return temp;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node *next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        Node* curr1=head;
        while(curr1!=NULL){
            curr1->next->random = (curr1->random!=NULL)?curr1->random->next:NULL;
            curr1=curr1->next->next;
        }
        Node* curr2=head;
        Node * res=NULL;
        Node* temp= NULL;
        res=temp=head->next;
        while(curr2!=NULL){
            Node* next = curr2->next->next;
            temp->next=curr2->next;
            temp=temp->next;
            curr2->next=next;
            curr2=next;
        }
        return res;
        
        
    }
};