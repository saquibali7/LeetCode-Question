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
    int pre=0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int ie, int is){
        if(ie>is){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre++]);
        int idx=0;
        for(int i=ie;i<=is;i++){
            if(root->val == inorder[i]){
                idx=i;
                break;
            }
        }
        root->left = helper(preorder,inorder, ie, idx-1);
        root->right = helper(preorder,inorder, idx+1,is);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int ie=0,is=n-1;
        TreeNode* root= helper(preorder,inorder,ie,is);
        return root;
    }
};