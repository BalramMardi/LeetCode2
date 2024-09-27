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

    int bfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int totalSum=0;
        queue<pair<TreeNode*,int>> queue;
        queue.push({root,root->val});
        while(queue.size()){
            int len = queue.size();
            for(int i=0;i<len;i++){
                auto [node,sum] = queue.front();
                queue.pop();
                if(!node->left and !node->right){
                    totalSum += sum;
                }
                if(node->left){
                    queue.push({node->left,sum*10+node->left->val});
                }
                if(node->right){
                    queue.push({node->right,sum*10+node->right->val});
                }
            }
        }

        return totalSum;
    }

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
        // solve(root, 0, totalSum);
        // return totalSum;
        return bfs(root);
    }
};