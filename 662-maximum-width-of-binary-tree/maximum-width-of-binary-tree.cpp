#define ll unsigned long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        // Queue to store the node and its position/index
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        int maxi = 0;

        while (!q.empty()) {
            int len = q.size();
            ll lefty = q.front().second; // Leftmost index in the current level
            ll righty = lefty;            // Rightmost index will be updated later
            
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                TreeNode* curr = node.first;
                ll idx = node.second; // Index of the current node
                
                // Update the rightmost index
                righty = idx;
                
                // Push children into the queue with updated indices
                if (curr->left) {
                    q.push({curr->left, 2 * idx + 1});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * idx + 2});
                }
            }
            
            // Calculate the width of the current level
            maxi = max(maxi, (int)(righty - lefty + 1));
        }
        
        return maxi;
    }
};