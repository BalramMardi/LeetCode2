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
    int dfs(TreeNode* node,int &maxi){
        if(!node){
            return 0;
        }

        int leftGain = max(dfs(node->left,maxi),0);
        int rightGain = max(dfs(node->right,maxi),0);

        int currentSum = node->val+leftGain+rightGain;

        maxi = max(maxi,currentSum);

        return node->val+max(leftGain,rightGain);

    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root,maxi);
        return maxi;
    }
};