class Solution {
public:
    struct trieNode {
        trieNode* left;
        trieNode* right;
    };

    void insert(trieNode* root, int num) {

        trieNode* curr = root;

        for (int i = 31; i >= 0; i--) {
            bool ith = (num >> i) & 1;

            if (!ith) {
                if (!curr->left) {
                    curr->left = new trieNode();
                }
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new trieNode();
                }
                curr = curr->right;
            }
        }
    }

    int maxSolver(trieNode* root, int num) {
        int maxOr = 0;
        trieNode* curr = root;

        for (int i = 31; i >= 0; i--) {
            int ith = (num >> i) & 1;
            if (ith == 1) {
                if (curr->left) {
                    maxOr += pow(2, i);
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            } else {
                if (curr->right) {
                    maxOr += pow(2, i);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }
        }

        return maxOr;
    }
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();

        for (int i = 0; i < nums.size(); i++) {
            insert(root, nums[i]);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, maxSolver(root, nums[i]));
        }
        return ans;
    }
};