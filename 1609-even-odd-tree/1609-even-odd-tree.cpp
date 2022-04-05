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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        bool flag=false;
        int prev=INT_MIN;
        while(q.size() > 1){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                flag=!flag;
                q.push(NULL);
                if(flag){
                    prev=INT_MAX;
                } else {
                    prev=INT_MIN;
                }
                continue;
            }
            if(!flag){
                if(curr->val%2==0){
                    return false;
                } 
                if(curr->val <= prev){
                    return false;
                }
                prev=curr->val;
                
            } else {
                if(curr->val%2!=0){
                    return false;
                } 
                if(curr->val >= prev){
                    return false;
                }
                prev=curr->val;
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        return true;
        
    }
};