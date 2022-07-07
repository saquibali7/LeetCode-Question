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
    int res = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        stack<TreeNode* > st;
        int res=INT_MAX,prev=-1;
        while(root || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            TreeNode* curr = st.top();
            st.pop();
            if(prev!=-1){
                res = min(res, abs(curr->val - prev));
            }
            prev=curr->val;
            root=curr->right;
        }
        return res;
        
    }
};