class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        // Count frequencies and determine the maximum frequency
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
            }
        }

        // Initialize the result matrix with the required number of rows
        vector<vector<int>> ans(maxFreq);

        // Distribute the elements into the rows
        for (const auto& [num, count] : freq) {
            for (int i = 0; i < count; ++i) {
                ans[i].push_back(num);
            }
        }

        return ans;
    }
};
