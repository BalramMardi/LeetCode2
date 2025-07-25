class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            if (num > 0) {
                st.emplace(num);
            }
        }

        if (st.empty()) {
            return *max_element(nums.begin(), nums.end());
        }
        
        return accumulate(st.begin(), st.end(), 0);
    }
};