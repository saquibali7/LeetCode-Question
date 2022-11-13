/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    string encode = "";
    void dfs(TreeNode *root) {
        if(root == NULL){
            encode+=" ";
            encode+=",";
            return;
        }
        encode+=to_string(root->val);
        encode+=",";
        dfs(root->left);
        dfs(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode * root) {
        dfs(root);
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() < 1) return NULL;
        return helper_deserialize(data);
    }
    int idx=0;
    TreeNode *helper_deserialize(string &data) {
        if(data.size() == 0) return NULL;
        if (data[idx] == ' ') {
            idx = idx+2;
            return NULL;
        }
        string temp = "";
        while (data[idx] != ',') temp += data[idx++];
        idx++;
        TreeNode *curr = new TreeNode(stoi(temp));
        curr->left = helper_deserialize(data);
        curr->right = helper_deserialize(data);
        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));