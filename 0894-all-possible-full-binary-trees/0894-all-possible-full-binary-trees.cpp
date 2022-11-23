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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n==1){
            return {new TreeNode(0)};
        } 
        if(n%2==0) return {};
        vector<TreeNode* > res;
        for(int i=1;i<n-1;i+=2){
            for(auto &l : allPossibleFBT(i)){
                for(auto &r : allPossibleFBT(n-i-1)){
                    TreeNode* root = new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                        
                }
            }
        }
        return res;
        
    }
};