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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        TreeNode* root = helper(nums,0,n-1);
        return root;
    }
    TreeNode* helper(vector<int> &nums, int low, int high){
        if(high<low){
            return NULL;
        }
        int max=nums[low],id=low;
        for(int i=low;i<=high;i++){
            if(nums[i] > max){
                max=nums[i];
                id=i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = helper(nums,low,id-1);
        root->right= helper(nums,id+1,high);
        return root;
    }
};