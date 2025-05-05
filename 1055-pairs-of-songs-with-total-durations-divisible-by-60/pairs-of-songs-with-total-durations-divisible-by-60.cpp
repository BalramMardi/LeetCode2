class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainder(60, 0);
        int count = 0;
        
        for(int t : time) {
            int rem = t % 60;

            // int complement = (rem == 0) ? 0 : 60-rem;

            int complement = (60-rem) % 60;

            count += remainder[complement];

            remainder[rem]++;
        }

        return count;
    }
};
