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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int res=0;
        if(root->val%2==0){
            if(root->left!=NULL && root->left->left!=NULL){
                res+=root->left->left->val;
            }
            if(root->left!=NULL && root->left->right!=NULL){
                res+=root->left->right->val;
            }
            if(root->right!=NULL && root->right->left!=NULL){
                res+=root->right->left->val;
            }
            if(root->right!=NULL && root->right->right!=NULL){
                res+=root->right->right->val;
            }
        }
        res+=sumEvenGrandparent(root->left);
        res+=sumEvenGrandparent(root->right);
        return res;
    }
};