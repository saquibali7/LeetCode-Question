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
    int count=0;
    void helper(TreeNode* root, int maximum){
        if(root==NULL){
            return;
        }
        if(root->val>=maximum){
            count++;
            maximum=root->val;
        }
        helper(root->left, maximum);
        helper(root->right, maximum);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maximum=INT_MIN;
        helper(root, maximum);
        return count;
        
    }
};