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
    int res;
    void helper(TreeNode* parent,TreeNode* child ){
        if(parent==NULL || child == NULL){
            return;
        }
        res = max(res, abs(parent->val-child->val));
        helper(parent, child->left);
        helper(parent, child->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        helper(root, root->left);
        helper(root, root->right);
        return max(res, max(maxAncestorDiff(root->left),maxAncestorDiff(root->right)));
        
        
    }
};