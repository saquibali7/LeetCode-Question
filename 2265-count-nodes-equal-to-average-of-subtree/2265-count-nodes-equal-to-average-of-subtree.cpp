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
    pair<int, int> helper(TreeNode* root, int& count){
        if(root==NULL){
            return {0,0};
        }
        if(root->left==NULL && root->right==NULL){
            count++;
            return {root->val,1};
        }
        auto l = helper(root->left,count);
        auto r = helper(root->right,count);
        int sum = l.first+r.first+root->val;
        int n=l.second+r.second+1;
        if(sum/n == root->val){
            count++;
        }
        return {sum,n};
        
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count=0;
        helper(root,count);
        return count;
    }
};