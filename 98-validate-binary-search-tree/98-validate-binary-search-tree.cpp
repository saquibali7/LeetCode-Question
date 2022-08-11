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
    int maxValue(TreeNode* root){
        if (root->right==NULL){
            return root->val;
        }
        else {
            return maxValue(root->right);
        }
    }
    int minValue(TreeNode* root){
        if (root->left==NULL){
            return root->val;
        }
        return minValue(root->left);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left!= NULL && maxValue(root->left) >=root->val){
            return false;
        }
        if(root->right!=NULL && minValue(root->right) <= root->val){
            return false;
        }
        if(!isValidBST(root->left) || !isValidBST(root->right)){
            return false;
        }
        return true;
    }
};