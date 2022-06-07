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
    vector<TreeNode* > res;
    unordered_set<int> st;
    TreeNode* helper(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        root->left = helper(root->left);
        root->right = helper(root->right);
        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL){
                res.push_back(root->left);
            }
            if(root->right!=NULL){
                res.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL){
            return res;
        }
        for(auto i : to_delete){
            st.insert(i);
        }
        helper(root);
        if(st.find(root->val)==st.end()){
            res.push_back(root);
        }
        return res;
    }
};