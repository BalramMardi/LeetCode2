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
    int maxLevelSum(TreeNode* root) {
        
        pair<int,int> maxi={root->val,1};

        queue<TreeNode*> q;

        q.push(root);
        int level=0;

        while(q.size()){

            level++;
            int sum=0;
            int len = q.size();
            

            for(int i=0;i<len;i++){
                
                auto curr = q.front();
                int val = curr->val;
                q.pop();

                sum += val;

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }

            }

            if(maxi.first < sum){
                maxi = {sum,level};
            }
        }

        return maxi.second;
    }
};