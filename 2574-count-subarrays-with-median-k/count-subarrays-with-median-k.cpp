class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        int kIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                kIndex = i;
                break;
            }
        }
        if (kIndex == -1) return 0;

       
        vector<int> transformed(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] > k) {
                transformed[i] = 1;
            } else if (nums[i] < k) {
                transformed[i] = -1;
            } else {
                transformed[i] = 0;
            }
        }

     
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        int prefix_sum = 0;
        bool kFound = false;

        for (int i = 0; i < n; i++) {
            prefix_sum += transformed[i];

     
            if (nums[i] == k) {
                kFound = true;
            }

            if (kFound) {
                if (prefix_counts.find(prefix_sum) != prefix_counts.end()) {
                    result += prefix_counts[prefix_sum];
                }

                if (prefix_counts.find(prefix_sum - 1) != prefix_counts.end()) {
                    result += prefix_counts[prefix_sum - 1];
                }
            }
            else{
                prefix_counts[prefix_sum]++;

            }

        }

        return result;
    }
};