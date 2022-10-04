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
    void helper(TreeNode* root, long long int v){
        if(root==NULL){
            return;
        }
        if(root->val == v){
            count++;
        }
        helper(root->left,v-root->val);
        helper(root->right, v-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        vector<TreeNode* > temp;
        stack<TreeNode* > st;
        while(root!=NULL || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            temp.push_back(root);
            root=root->right;
        }
        for(int i=0;i<temp.size();i++){
            helper(temp[i],targetSum);
        }
        return count;
    }
};