class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> seen(128);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (seen[nums[i]]) {
                return i / 3 + 1;
            }
            seen[nums[i]] = true;
        }
        return 0;
    }
};

/* class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto checkUnique = [&](int start) {
            unordered_set<int> seen;
            for (int i = start; i < nums.size(); i++) {
                if (seen.count(nums[i])) {
                    return false;
                }
                seen.emplace(nums[i]);
            }
            return true;
        };

        int ans = 0;
        for (int i = 0; i < nums.size(); i += 3, ans++) {
            if (checkUnique(i)) {
                return ans;
            }
        }
        return ans;
    }
}; */