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
    TreeNode* helper(vector<int> &preorder, int l, int r){
        if(l>r){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[l]);
        if(l==r){
            return root;
        }
        int idx=l+1;
        bool flag=false;
        for(int i=l;i<=r;i++){
            if(preorder[i]>preorder[l]) {
                idx=i;
                flag=true;
                break;
            }
        }
        if(!flag){
            root->left=helper(preorder,l+1,r);
        }
        else {
            root->left = helper(preorder,l+1,idx-1);
            root->right = helper(preorder,idx,r);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};