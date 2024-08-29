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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd){
        if(inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int i=inStart;
        while(i<=inEnd){
            if(inorder[i] == root->val){
                break;
            }
            i++;
        }
        int leftSide = i-inStart;
        int rightSide = inEnd - i;

        root->left = solve(inorder,postorder,inStart,i-1,postStart,postStart+leftSide-1);
        root->right = solve(inorder,postorder,i+1,inEnd,postEnd-rightSide,postEnd-1);

        return root;

    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();

        if(n==0){
            return NULL;
        }

        TreeNode* ans = solve(inorder,postorder,0,n-1,0,n-1);
        return ans;
    }
};