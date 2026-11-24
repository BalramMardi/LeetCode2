class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 2;
        int product = 1;
        int n = nums.size();
        int start = 0, end = 0;

        while (end < n) {
            while (gcd(product, nums[end]) > 1) {
                product /= nums[start];
                start++;
            }
            product *= nums[end];
            res = max(res, end - start + 1);
            end++;
        }
        return res;
    }
};