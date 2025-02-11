class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> balanceCount;
        int pivotIndex = find(nums.begin(), nums.end(), k) - nums.begin();
        int result = 0;

        for (int i = pivotIndex, balance = 0; i < nums.size(); ++i) {
            if (nums[i] > k)
                balance += 1;
            else if (nums[i] < k)
                balance -= 1;
            ++balanceCount[balance];
        }

        for (int i = pivotIndex, balance = 0; i >= 0; --i) {
            if (nums[i] > k)
                balance += 1;
            else if (nums[i] < k)
                balance -= 1;

            result += balanceCount[-balance] + balanceCount[-balance + 1];
        }

        return result;
    }
};