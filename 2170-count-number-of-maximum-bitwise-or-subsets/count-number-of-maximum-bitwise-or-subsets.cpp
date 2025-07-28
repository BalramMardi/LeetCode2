class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOrValue = 0;

        for (int num : nums) {
            maxOrValue |= num;
        }

        vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1));

        return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo);
    }

private:
    int countSubsetsRecursive(vector<int>& nums, int index, int currentOr,
                              int targetOr, vector<vector<int>>& memo) {
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }

        if (memo[index][currentOr] != -1) {
            return memo[index][currentOr];
        }

        int countWithout = countSubsetsRecursive(nums, index + 1, currentOr, targetOr, memo);

        int countWith = countSubsetsRecursive( nums, index + 1, currentOr | nums[index], targetOr, memo);

        return memo[index][currentOr] = countWithout + countWith;
    }
};

/* 
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int n : nums) maxOr |= n;

        int badSubsets = 0;

        for (int mask = maxOr; mask; mask = (mask - 1) & maxOr) {
            int cnt = 0;

            for (int n : nums)
                if ((n & mask) == 0)
                    cnt++;

            int sign = (__builtin_popcount(mask) & 1) ? 1 : -1;
            badSubsets += sign * ((1 << cnt) - 1);
        }

        int totalSubsets = (1 << nums.size()) - 1;
        return totalSubsets - badSubsets;
    }
};
 */