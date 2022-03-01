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
    int preIndex=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int is=0,ie=n-1;
        TreeNode* root = helper(preorder,inorder,is,ie);
        return root;
        
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int is, int ie){
        if(is>ie){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        int inIndex=0;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                inIndex=i;
                break;
            }
        }
        root->left = helper(preorder,inorder,is,inIndex-1);
        root->right = helper(preorder,inorder,inIndex+1,ie);
        return root;
    }
};