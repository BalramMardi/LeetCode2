class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi = *max_element(nums.begin(), nums.end());
        int arr = maxi + k + 2;
        vector<int> counter(arr, 0);

        for (int num : nums)
        {
            counter[num]++;
        }

        vector<int> prefixSum(arr, 0);
        prefixSum[0] = counter[0];

                for (int i = 1; i < arr; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + counter[i];
        }

        int maxfreq = 0;
        for (int value = 0; value < arr; value++)
        {
            if (counter[value] == 0 && numOperations == 0)
            {
                continue;
            }

            int rightb = min(arr - 1, value + k);
            int leftb = max(0, value - k);
            int pa = (prefixSum[rightb] - (leftb > 0 ? prefixSum[leftb - 1] : 0)) - counter[value];
            int total = counter[value] + min(numOperations, pa);
            maxfreq = max(maxfreq, total);
        }

        return maxfreq;
    }
};