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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root == NULL){
            return res;
        }
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        while(s1.empty() == false || s2.empty() == false){
            while(s1.empty() == false){
                TreeNode* curr=s1.top();
                s1.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL){
                    s2.push(curr->left);
                }
                if(curr->right!=NULL){
                    s2.push(curr->right);
                }
            }
            if(temp.size() > 0) {
                 res.push_back(temp);
                 temp.clear();   
            }
            while(s2.empty() == false){
                TreeNode *curr = s2.top();
                s2.pop();
                temp.push_back(curr->val);
                if(curr->right!=NULL){
                    s1.push(curr->right);
                }
                if(curr->left!=NULL){
                    s1.push(curr->left);
                }
            }
            if(temp.size() > 0) {
                 res.push_back(temp);
                 temp.clear();   
            }
           
        }
        return res;
    }
};