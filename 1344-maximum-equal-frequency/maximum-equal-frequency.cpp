class Solution {
public:

    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> count;  
        unordered_map<int, int> freq;   
        int res = 0, maxFreq = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int prevCount = count[num];

        
            if (prevCount > 0) {
                freq[prevCount]--;
                if (freq[prevCount] == 0) {
                    freq.erase(prevCount);
                }
            }

        
            count[num]++;
            int newCount = count[num];
            freq[newCount]++;

            maxFreq = max(maxFreq, newCount);

            int len = i + 1;
            // Case 1: all numbers are 1 frequency
            if (maxFreq == 1) res = len;
            // Case 2: one element occurs once, rest occur maxFreq
            else if (freq[maxFreq] * maxFreq + 1 == len) res = len;
            // Case 3: one element occurs maxFreq times, rest maxFreq-1
            else if (freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == len && freq[maxFreq] == 1)
                res = len;
        }

        return res;
    }

};