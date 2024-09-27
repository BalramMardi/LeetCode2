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

     void solve(TreeNode* root, int currentSum, int &totalSum) {
        if (!root) return; 

        // Update the current sum by appending the node's value.
        currentSum = currentSum * 10 + root->val;

        // If it's a leaf node, add the current sum to totalSum.
        if (!root->left && !root->right) {
            totalSum += currentSum;
            return;
        }

      
        solve(root->left, currentSum, totalSum);
        solve(root->right, currentSum, totalSum);
    }


    int sumNumbers(TreeNode* root) {
         int totalSum = 0;
        solve(root, 0, totalSum);
        return totalSum;
    }
};