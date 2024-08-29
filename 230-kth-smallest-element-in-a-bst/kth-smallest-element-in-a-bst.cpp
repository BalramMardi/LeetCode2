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
    void inorder(TreeNode* root,vector<int> &inord){
        if(!root){
            return;
        }

        inorder(root->left,inord);
        inord.push_back(root->val);
        inorder(root->right,inord);     
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        vector<int> inord;
        inorder(root,inord);

        return inord[k-1];

    }
};