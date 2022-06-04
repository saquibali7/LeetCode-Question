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
    int sum;
    void helper(TreeNode* root, vector<int> temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            int res=0,temp1=1;
            for(int i=temp.size()-1;i>=0;i--){
                res+=temp1*temp[i];
                temp1*=2;
            }
            sum+=res;
            return;
        }
        temp.push_back(root->val);
        helper(root->left,temp);
        helper(root->right,temp);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int> temp;
        helper(root,temp);
        return sum;
        
    }
};