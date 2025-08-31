
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int count = countFromNode(root, targetSum);

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }

    int countFromNode(TreeNode* node, long long target) {
        if (!node) return 0;

        int cnt = 0;
        if (node->val == target) cnt++;

        cnt += countFromNode(node->left, target - node->val);
        cnt += countFromNode(node->right, target - node->val);

        return cnt;
    }
};
