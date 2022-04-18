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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return NULL;;
        }
        long long int prev_sum=0;
        TreeNode* curr=root;
        stack<TreeNode *> s;
        while(s.empty()==false|| curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->right;
            }
            curr=s.top();
            s.pop();
            curr->val+=prev_sum;
            prev_sum=curr->val;  
            curr=curr->left;
        }
        return root;
        
    }
};