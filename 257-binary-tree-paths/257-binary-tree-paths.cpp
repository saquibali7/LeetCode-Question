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
    vector<string> res;
    void helper(TreeNode* root, string temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp+=to_string(root->val);
            res.push_back(temp);
            return;
        }
        temp+=to_string(root->val)+"->";
        helper(root->left,temp);
        helper(root->right,temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp="";
        helper(root,temp);
        return res;
    }
};