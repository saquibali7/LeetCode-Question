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
    void helper(TreeNode* root, int l, int r, int &count){
        if(root==NULL){
            return;
        }
        count = max(count,l);
        count = max(count,r);
        helper(root->left,0,l+1,count);
        helper(root->right,r+1,0,count);
        
    }
    int longestZigZag(TreeNode* root) {
        int count=0;
        helper(root,0,0,count);
        return count;
    }
};