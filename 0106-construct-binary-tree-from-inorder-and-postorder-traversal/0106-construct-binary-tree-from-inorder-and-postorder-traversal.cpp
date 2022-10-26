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
    int postIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int is=0,ie=n-1;
        postIndex=n-1;
        TreeNode *root = helper(inorder,postorder,is,ie);
        return root;
    }
    TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int is, int ie){
        if(is>ie){
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postIndex--]);
        int inIndex=0;
        for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                inIndex=i;
                break;
            }
        }
        root->right = helper(inorder,postorder,inIndex+1,ie);
        root->left = helper(inorder,postorder,is,inIndex-1);
        return root;
    }
};