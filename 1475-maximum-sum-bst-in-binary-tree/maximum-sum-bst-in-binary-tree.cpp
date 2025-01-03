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

    struct Subtree{
        bool isBST;
        int minVal;
        int maxVal;
        int sumVal;
        int maxSum;
    };

    Subtree helper(TreeNode* root, int &maxSum){
        if(!root){
            return {true,INT_MAX,INT_MIN,0,0};
        }

        auto left = helper(root->left,maxSum);
        auto right = helper(root->right,maxSum);

        if(left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal){
           int sumVal = root->val + left.sumVal + right.sumVal;
           maxSum = max(maxSum,sumVal);
           return {true,min(left.minVal,root->val),max(right.maxVal,root->val),sumVal,maxSum};
        }
        return {false,0,0,0,max(left.maxSum,right.maxSum)};
    }

    int maxSumBST(TreeNode* root) {
        int maxSum=0;
        helper(root,maxSum);
        return maxSum;
    }
};