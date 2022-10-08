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
    int res=INT_MIN;
    void helper(TreeNode* root, unordered_map<int,vector<int>> &m, int p){
        if(root==NULL){
            return;
        }
        if(p!=-1){
            m[root->val].push_back(p);
        }
        if(root->left!=NULL){
            m[root->val].push_back(root->left->val);
        }
        if(root->right!=NULL){
            m[root->val].push_back(root->right->val);
        }
        helper(root->left,m,root->val);
        helper(root->right,m,root->val);
    }
    void dfs(unordered_map<int,vector<int>> &m, unordered_set<int> &s, int sr,int count){
        if(s.find(sr)!=s.end()){
            return;
        }
        s.insert(sr);
        res=max(res,count);
        for(auto u : m[sr]){
            if(s.find(u)==s.end()){
                dfs(m,s,u,count+1);
            }
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> m;
        helper(root,m,-1);
        unordered_set<int> s;
        dfs(m,s,start,0);
        return res;
        
    }
};