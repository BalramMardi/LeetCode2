class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix; 
        prefix[0] = 1; 
        return dfs(root, 0, targetSum, prefix);
    }

    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long,int>& prefix) {
        if (!node) return 0;

        currSum += node->val;
        int count = 0;

        if (prefix.count(currSum - target)) {
            count += prefix[currSum - target];
        }

        prefix[currSum]++;

        count += dfs(node->left, currSum, target, prefix);
        count += dfs(node->right, currSum, target, prefix);

        prefix[currSum]--; 

        return count;
    }
};

/* 
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
 */