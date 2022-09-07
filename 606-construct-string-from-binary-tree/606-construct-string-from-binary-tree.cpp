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
    string res="";
    void helper(TreeNode* root){
        if(root==NULL){
            res+="()";
            return;
        }
        res+="(";
        res+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            res+=")";
            return;
        }
        
        helper(root->left);
        if(root->right==NULL){
            res+=")";
            return;
        }
        helper(root->right);
        res+=")";
    }
    string tree2str(TreeNode* root) {
        helper(root);
        string result = res.substr(1,res.size()-2);
        return result;
    }
};