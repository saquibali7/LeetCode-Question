/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        int count=0;
        while(q.size()>1){
            Node * temp=q.front();
            q.pop();
            if(temp==NULL){
                count++;
                q.push(NULL);
                continue;
            }
            for(int i=temp->children.size()-1;i>=0;i--){
                q.push(temp->children[i]);
            }
        }
        return count+1;
        
    }
};