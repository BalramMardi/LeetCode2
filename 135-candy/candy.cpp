class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        vector<int> candies(n, 1);

        // Left to right: ensure right higher-rated child gets more candies than the left one
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left: ensure left higher-rated child gets more candies than the right one
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }


        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += candies[i];
        }

        return sum;
    }
};
