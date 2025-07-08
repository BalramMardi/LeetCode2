class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int left = 0, count = 0, odd = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] & 1) odd++;

            while (odd > k) {
                if (nums[left] & 1) odd--;
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};



/* class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int oddCount = 0;
        int count = 0;
        for(int num: nums){
            oddCount += (num % 2 != 0);
            int needed = oddCount-k;
            if (mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            mp[oddCount]++;
        }
        return count;
    }
}; */