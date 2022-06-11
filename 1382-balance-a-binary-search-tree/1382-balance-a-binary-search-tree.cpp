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
    vector<int> res;
    void tvs(TreeNode* root){
        if(root!=NULL){
            tvs(root->left);
            res.push_back(root->val);
            tvs(root->right);
        }
    }
    TreeNode* helper(vector<int> temp, int low,int high){
        if(low>high){
            return NULL;
        }
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(temp[mid]);
        root->left = helper(temp,low,mid-1);
        root->right = helper(temp, mid+1,high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        tvs(root);
        TreeNode *re = helper(res,0,res.size()-1);
        return re;
        
        
    }
};