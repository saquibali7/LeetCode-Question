/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
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
    void dfs(unordered_map<int,vector<int>> &m, unordered_set<int> &s, int sr,int count,int k){
        if(s.find(sr)!=s.end()){
            return;
        }
        if(count==k){
            res.push_back(sr);
        }
        s.insert(sr);
        for(auto u : m[sr]){
            if(s.find(u)==s.end()){
                dfs(m,s,u,count+1,k);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> m;
        helper(root,m,-1);
        unordered_set<int> s;
        dfs(m,s,target->val,0,k);
        return res;
    }
};