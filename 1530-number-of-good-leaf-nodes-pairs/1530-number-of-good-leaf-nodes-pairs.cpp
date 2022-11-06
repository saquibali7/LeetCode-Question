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
    int res=0;
    vector<int> helper(TreeNode* root, int &d){
        if(root==NULL){
            return {};
        }
        if(root->left==NULL && root->right==NULL){
            return {1};
        }
        vector<int> l = helper(root->left,d);
        vector<int> r = helper(root->right,d);
        for(auto i : l){
            for(auto j : r){
                if(i+j<=d) res++;
            }
        }
        vector<int> temp;
        for(auto i : l){
            temp.push_back(i+1);
        }
        for(auto i : r){
            temp.push_back(i+1);
        }
        return temp;
    }
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return res;
    }
};