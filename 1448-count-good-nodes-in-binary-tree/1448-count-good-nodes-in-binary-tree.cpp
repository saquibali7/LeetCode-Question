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
    int count=0;
    void helper(TreeNode* root, vector<int> temp){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        bool flag=flag;
        if(temp.size()==1){
            count++;
        } else {
            for(int i=temp.size()-2;i>=0;i--){
                if(temp[i]>root->val){
                    flag=true;
                    break;
                }
            }
            if(!flag){
            count++;
            }
        }
        helper(root->left,temp);
        helper(root->right,temp);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int> temp;
        helper(root,temp);
        return count;
        
    }
};