class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainder(60, 0);
        int count = 0;
        
        // Count the remainder frequencies
        for(int t : time) {
            int rem = t % 60;
            
            // If the remainder is 0, look for other songs with remainder 0
            if (rem == 0) {
                count += remainder[0];
            } else {
                // Otherwise, look for songs that complement this remainder to make 60
                count += remainder[60 - rem];
            }
            
            // Increment the remainder frequency
            remainder[rem]++;
        }

        return count;
    }
};
