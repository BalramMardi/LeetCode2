class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; ++i) {
            vector<bool> seen(1002, false);  
            int imbalance = 0;

            seen[nums[i]] = true;

            for (int j = i + 1; j < n; ++j) {
                int x = nums[j];
                if (!seen[x]) {
                    if (seen[x - 1] && seen[x + 1]) {
                        imbalance -= 1;
                    } else if (!seen[x - 1] && !seen[x + 1]) {
                        imbalance += 1;
                    }
                   
                    seen[x] = true;
                }
                total += imbalance;
            }
        }

        return total;
    }
};
