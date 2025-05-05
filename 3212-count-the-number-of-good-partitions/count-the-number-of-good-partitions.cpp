class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> last;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            last[nums[i]] = i;
        }

        int end = 0, cuts = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[nums[i]]);
            if (i == end) {
                cuts++;
            }
        }

        return cuts == 0 ? 1 : power(2, cuts - 1);
    }

    int power(int base, int exp) {
        long long result = 1;
        long long b = base;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }

        return result;
    }
};
