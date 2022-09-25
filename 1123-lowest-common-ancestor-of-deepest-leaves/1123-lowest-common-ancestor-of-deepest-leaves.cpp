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
    TreeNode *lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* l = lca(root->left,p,q);
        TreeNode* r = lca(root->right, p, q);
        if(l && r){
            return root;
        }
        if(l==NULL){
            return r;
        }
        if(r==NULL){
            return l;
        }
        return NULL;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode* > temp;
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        while(q.size()> 1){
            TreeNode* curr = q.front();
            q.pop();
            if(curr==NULL){
                q.push(NULL);
                temp.clear();
                continue;
            }
            temp.push_back(curr);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        return lca(root, temp[0], temp[temp.size()-1]);
    }
};