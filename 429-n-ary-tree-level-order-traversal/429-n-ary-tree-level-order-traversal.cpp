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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        vector<int> temp;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 1){
            Node* curr=q.front();
            q.pop();
            if(curr==NULL){
                q.push(NULL);
                res.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(curr->val);
            for(int i=0;i<curr->children.size();i++){
                if(curr->children[i]!=NULL){
                    q.push(curr->children[i]);
                }
            }
        }
        res.push_back(temp);
        return res;
        
    }
};