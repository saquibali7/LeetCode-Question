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
    int helper(TreeNode* root,unordered_map<int,int> &m ){
        if(root==NULL){
            return -1;
        }
        if(root->left==NULL && root->right==NULL){
            m[root->val]++;
            return root->val;
        }
        int v;
        int l = helper(root->left, m);
        int r = helper(root->right, m);
        if(l!=-1 && r!=-1){
            v=l+r+root->val;
        } else if(r!=-1){
            v=r+root->val;
        } else {
            v=l+root->val;
        }
        m[v]++;
        return v;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        unordered_map<int, int> m;
        helper(root,m);
        int f=0;
        for(auto it : m){
            if(it.second > f){
                f=it.second;
            }
        }
        for(auto it : m){
            if(it.second==f){
                res.push_back(it.first);
            }
        }
        return res;
        
    }
};