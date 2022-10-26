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
    int res=INT_MIN;
    int helper(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right == NULL){
            res=max(res,root->val);
            return root->val;
        }
        int l = helper(root->left);
        int r = helper(root->right);
        
        res = max(res,root->val+l+r);
        res = max(res,root->val+l);
        res = max(res,root->val+r);
        res = max(res,root->val);
        int temp = max(root->val,max(root->val+l,root->val+r));
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
};