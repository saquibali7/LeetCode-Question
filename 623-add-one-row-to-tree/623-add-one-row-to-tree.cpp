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
    int d,v;
    void helper(TreeNode* root, int level){
        if(root==NULL){
            return;
        }
        if(level+1==d){
            TreeNode* temp=new TreeNode(v);
            TreeNode* temp2=new TreeNode(v);
            temp->left=root->left;
            temp2->right = root->right;
            root->left=temp;
            root->right=temp2;
            return;
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* res=new TreeNode(val);
            res->left=root;
            return res;
        }
        d=depth;
        v=val;
        helper(root,1);
        return root;
        
    }
};