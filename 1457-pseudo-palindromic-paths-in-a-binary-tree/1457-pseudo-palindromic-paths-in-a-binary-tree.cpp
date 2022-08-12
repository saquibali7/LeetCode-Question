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
    void helper(TreeNode* root, vector<int> temp, int& count){
        if(root==NULL){
            return;
        }
        temp[root->val]++;;
        if(root->left==NULL && root->right == NULL){
            int temp1=0;
            for(int i=0;i<temp.size();i++){
                if(temp[i]%2!=0){
                    temp1++;
                }
            }
            if(temp1<=1){
                count++;
            }
            return;
        }
        helper(root->left, temp,count);
        helper(root->right, temp,count);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int> temp(10,0);
        helper(root,temp,count);
        return count;
    }
};