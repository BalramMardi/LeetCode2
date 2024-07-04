class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> dp = robHelper(root);
        return max(dp[0], dp[1]);
    }

private:
    vector<int> robHelper(TreeNode* node) {
        if (!node) return {0, 0};

        vector<int> left = robHelper(node->left);
        vector<int> right = robHelper(node->right);

        int robCurr = node->val + left[1] + right[1];
        int notRobCurr = max(left[0], left[1]) + max(right[0], right[1]);

        return {robCurr, notRobCurr};
    }
};