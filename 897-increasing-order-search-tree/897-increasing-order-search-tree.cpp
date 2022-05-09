/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* res=NULL;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode* res=NULL;
        TreeNode* curr1=NULL;
        
        stack<TreeNode *> s;
        while(root!=NULL || s.empty()==false){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(res==NULL){
                curr1=res=new TreeNode(root->val);
            }
            else {
                res->right=new TreeNode(root->val);
                res=res->right;
            }
            root=root->right;
        }
       return curr1;   
    }
};