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
    pair<int,int> helper(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->val,1};
        }
        pair<int,int> l = helper(root->left);
        pair<int,int> r = helper(root->right);
        if(l.first == r.first && l.first==root->val){
            res = max(res,r.second+l.second);
            return {root->val,max(r.second,l.second)+1};
        } else if(r.first==root->val){
            res = max(res,r.second);
            return {root->val,r.second+1};
        } else if(l.first==root->val){
            res = max(res,l.second);
            return {root->val,l.second+1};
        }
        return {root->val,1};
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return res;
    }
};