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
    string res = "";
    void dfs(TreeNode *root) {
        if (root != NULL) {
            res += to_string(root->val);
            res += ",";
            dfs(root->left);
            dfs(root->right);
        }
        else {
            res += "n";
            res += ",";
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode * root) {
        dfs(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() < 1)
            return NULL;
        return helper_deserialize(data);
    }
    TreeNode *helper_deserialize(string & data) {
        if (data.size() == 0)
            return NULL;
        if (data[0] == 'n')
        {
            data = data.substr(2);
            return NULL;
        }
        int pos = 0;
        string no = "";
        while (data[pos] != ',')
            no += data[pos++];
        TreeNode *curr = new TreeNode(stoi(no));
        data = data.substr(pos + 1);
        curr->left = helper_deserialize(data);
        curr->right = helper_deserialize(data);
        return curr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));