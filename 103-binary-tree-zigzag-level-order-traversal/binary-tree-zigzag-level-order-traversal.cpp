/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        bool isLeft = true;

        while (queue.size()) {
            int size = queue.size();

            vector<int> level;
            for (int i = 0; i < size; i++) {

                TreeNode* node = queue.front();
                queue.pop();
                if (isLeft) {
                    level.push_back(node->val);
                } else {
                    level.insert(level.begin(), node->val);
                }

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            isLeft = !isLeft;
            ans.push_back(level);
        }

        return ans;
    }
};