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
    void helper(TreeNode* root, string s){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            s+=root->val+97;
            reverse(s.begin(),s.end());
            if(res.length()==0){
               res=s; 
               return; 
            }
            res = min(res,s);
            return;
        }
        s+=root->val+97;
        helper(root->left, s);
        helper(root->right, s);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        if(root==NULL){
            return s;
        }
        helper(root,s);
        return res;
    }
};