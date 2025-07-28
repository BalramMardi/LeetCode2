
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
