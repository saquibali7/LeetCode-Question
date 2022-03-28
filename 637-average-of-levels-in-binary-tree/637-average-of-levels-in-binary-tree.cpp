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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        double count=0,res=0;
        while(q.size() > 1){
            TreeNode *curr = q.front();
            q.pop();
            if(curr==NULL){
                double avg;
                if(count!=0){
                    avg = res/count;
                }
                result.push_back(avg);
                res=0,count=0;
                q.push(NULL);
                continue;
            }
            res+=curr->val;
            count++;
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                 q.push(curr->right);
            }
        }
        double avg1 = res/count;
        result.push_back(avg1);
        return result;
        
    }
};