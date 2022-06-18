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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> s;
        unordered_map<int,vector<pair<int,int>>> m1;
        for(int i=0;i<descriptions.size();i++){
            s.insert(descriptions[i][1]);
            m1[descriptions[i][0]].push_back({descriptions[i][1],descriptions[i][2]});
        }
        int root=-1;
        for(int i=0;i<descriptions.size();i++){
            if(s.find(descriptions[i][0])==s.end()){
                root=descriptions[i][0];
            }
        }
        stack<TreeNode* > st;
        TreeNode* res = new TreeNode(root);
        st.push(res);
        while(!st.empty()){
            TreeNode* curr= st.top();
            st.pop();
            for(int i=0;i<m1[curr->val].size();i++){
                TreeNode *temp = new TreeNode(m1[curr->val][i].first);
                if(m1[curr->val][i].second==1){
                    curr->left=temp;
                } else {
                    curr->right=temp;
                }         
                st.push(temp);
            }
        }
        return res;
        
    }
};