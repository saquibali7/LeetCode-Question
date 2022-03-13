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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode* >q;
        q.push(root);
        int res=INT_MIN;
        q.push(NULL);
        while(q.size() > 1){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                result.push_back(res);
                res=INT_MIN;
                q.push(NULL);
                continue;
            }
            res=max(res,curr->val);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        result.push_back(res);
        return result;
    }
};