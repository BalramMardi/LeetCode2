class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;

        for(int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }

        int result = n;

        for(auto& [val, pos] : indices) {
            int maxGap = 0;
            int m = pos.size();

            for(int i = 0; i < m; ++i) {
              
                int curr = pos[i];
                int next = pos[(i + 1) % m] + (pos[(i + 1) % m] <= curr ? n : 0);
                maxGap = max(maxGap, next - curr);
            }


            result = min(result, maxGap / 2);
        }

        return result;
    }
};
