class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;
        
        int ans=0;
        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }

            ans= max(ans, right-left+1);
        }
        
        // return nums.size() - left;
        return ans;
    }
};

/* class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       
    sort(nums.begin(), nums.end());

    long long int left = 0;
    long long int maxFreq = 0;
    long long sum = 0;

    for (long long int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

      
        while ((right - left + 1) * nums[right]-sum > k )
        {
            sum -= nums[left];
            left++;
        }

        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq; 
    }
}; */