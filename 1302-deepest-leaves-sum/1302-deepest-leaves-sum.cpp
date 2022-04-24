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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(q.size() > 1){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                temp.clear();
                q.push(NULL);
                continue;
            }
            temp.push_back(curr->val);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        int res=0;
        for(int i=0;i<temp.size();i++){
            res+=temp[i];
        }
        return res;
    }
};