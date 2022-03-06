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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->val > val){
                if(curr->left == NULL){
                    curr->left = new TreeNode(val);
                    return root;
                }
                curr=curr->left;
            }
            else {
                if(curr->right == NULL){
                    curr->right = new TreeNode(val);
                    return root;
                }
                curr=curr->right;
            }
        }
        return root;
        
    }
};