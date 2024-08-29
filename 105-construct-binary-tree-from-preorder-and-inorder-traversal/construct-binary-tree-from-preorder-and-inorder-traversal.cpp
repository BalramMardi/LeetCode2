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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,int preStart,int preEnd){
        if(inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int i = inStart;
        while(i <= inEnd){
            if(inorder[i] == root->val){
                break;
            }
            i++;
        }
        int leftside = i-inStart;
        int rightside = inEnd-i;

        root->left = solve(preorder,inorder,inStart,i-1,preStart+1,preStart+leftside);
        root->right = solve(preorder,inorder,i+1,inEnd,preStart+leftside+1,preEnd);

        return root;

    } 


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n == 0) {
            return NULL;
        }

        return solve(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};