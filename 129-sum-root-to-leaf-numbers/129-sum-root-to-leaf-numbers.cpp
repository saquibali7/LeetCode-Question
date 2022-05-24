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
    vector<int> res;
    void helper(TreeNode* root, vector<int> temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(temp.size()>0){
                res.push_back(root->val + temp[temp.size()-1]*10);
            } else {
                res.push_back(root->val);
            }
            return;
        }
        if(temp.size()>0){
            temp.push_back(root->val+temp[temp.size()-1]*10);
        } else {
            temp.push_back(root->val);
        }
        helper(root->right,temp);
        helper(root->left,temp);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> temp;
        helper(root,temp);
        int sum=0;
        for(auto it : res){
            sum+=it;
        }
        return sum;
        
    }
};