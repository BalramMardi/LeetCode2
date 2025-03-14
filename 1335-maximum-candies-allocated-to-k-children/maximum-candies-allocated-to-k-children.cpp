class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid; 
        }
        return count >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k) return 0; 

        int low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAllocate(candies, k, mid)) {
                ans = mid; 
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
