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
    void helper(TreeNode* root, int &count, int maximum){
        if(root==NULL){
            return;
        }
        if(root->val>=maximum){
            count++;
            maximum=root->val;
        }
        helper(root->left, count, maximum);
        helper(root->right, count, maximum);
        
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        if(root==NULL){
            return count;
        }
        int mx = INT_MIN;
        helper(root, count, mx);
        return count;
    }
};