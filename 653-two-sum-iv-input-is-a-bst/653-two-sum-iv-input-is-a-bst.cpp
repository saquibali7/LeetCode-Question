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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        vector<int> temp;
        stack<TreeNode* > st;
        while(root!=NULL || !st.empty()){
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            temp.push_back(root->val);
            root=root->right;
        }
        int low=0,high=temp.size()-1;
        while(low<high){
            if(temp[low]+temp[high]==k){
                return true;
            } else if(temp[low]+temp[high]>k){
                high--;
            } else {
                low++;
            }
        }
        return false;
        
        
    }
};