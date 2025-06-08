class Solution {
public:
    struct trieNode {
        trieNode* zero;
        trieNode* one;
    };

    void insert(trieNode* root, int num) {

        trieNode* curr = root;

        for (int i = 31; i >= 0; i--) {
            bool ith = (num >> i) & 1;

            if (!ith) {
                if (!curr->zero) {
                    curr->zero = new trieNode();
                }
                curr = curr->zero;
            } else {
                if (!curr->one) {
                    curr->one = new trieNode();
                }
                curr = curr->one;
            }
        }
    }

    int maxSolver(trieNode* root, int num) {
        int maxOr = 0;
        trieNode* curr = root;

        for (int i = 31; i >= 0; i--) {
            int ith = (num >> i) & 1;
            if (ith == 1) {
                if (curr->zero) {
                    maxOr += pow(2, i);
                    curr = curr->zero;
                } else {
                    curr = curr->one;
                }
            } else {
                if (curr->one) {
                    maxOr += pow(2, i);
                    curr = curr->one;
                } else {
                    curr = curr->zero;
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