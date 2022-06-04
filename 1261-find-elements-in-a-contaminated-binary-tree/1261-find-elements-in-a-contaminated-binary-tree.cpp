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
class FindElements {
public:
    TreeNode* res;
    int count=0;
    unordered_set<int> st;
    void helper(int prev, TreeNode* child){
        if(child==NULL){
            return;
        }
        if(prev==-1){
            child->val=0;
            st.insert(child->val);
        } else {
            child->val=prev;
            st.insert(child->val);
        }
        helper(2*child->val+1,child->left);
        helper(2*child->val+2, child->right);
        
        
    }
    FindElements(TreeNode* root) {
        res=root;
        helper(-1,root);
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */