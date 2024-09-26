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
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }
        
        for (int i = start; i <= end; i++) {
            // Generate all left and right subtrees
            vector<TreeNode*> leftTrees = solve(start, i - 1);
            vector<TreeNode*> rightTrees = solve(i + 1, end);
            
            // Connect left and right subtrees to the current root i
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
          if (n == 0) return {};
        return solve(1, n);
    }
};