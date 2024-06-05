class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pos = -1;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (pos != -1) {
                    return false;
                }
                pos = i;
            }
        }

        // If no pair (nums[i], nums[i+1]) found that violates the non-decreasing order
        if (pos == -1) return true;

        // If violation is at the start or at the end of the array
        if (pos == 0 || pos == n - 2) return true;

        // Check if modifying nums[pos] or nums[pos+1] would make the array non-decreasing
        if (nums[pos - 1] <= nums[pos + 1] || nums[pos] <= nums[pos + 2]) return true;

        return false;
    }
};
