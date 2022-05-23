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
class CBTInserter {
public:
    TreeNode* res;
    CBTInserter(TreeNode* root) {
        res=root;
    }
    
    int insert(int val) {
        TreeNode* temp = new TreeNode(val);
        queue<TreeNode *> q;
        q.push(res);
        while(q.size()>0){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left==NULL){
                    curr->left=temp;
                    return curr->val;
                }
                if(curr->right==NULL){
                    curr->right=temp;
                    return curr->val;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return res;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */