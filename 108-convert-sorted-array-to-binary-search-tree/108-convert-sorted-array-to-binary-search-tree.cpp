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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        return helper(nums,low,high);
    }
    TreeNode* helper(vector<int>& nums, int low, int high){
        if(low>high){
            return NULL;
        }
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums,low,mid-1);
        root->right = helper(nums,mid+1,high);
        return root;
    }
};