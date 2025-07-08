class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long count = 0, pairs = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
          
            pairs += freq[nums[right]];
            freq[nums[right]]++;

      
            while (pairs >= k) {
                count += (nums.size() - right);
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }
        return count;
    }
};


/* class Solution{
public:
    long long countGood(vector<int>& A, int k) {
        long long res = 0;
        unordered_map<int, int> count;
        for (int left = 0, right = 0; right< A.size(); ++right) {
            k -= count[A[right]]++;
            while (k <= 0)
                k += --count[A[left++]];
            res += left;
        }
        return res;
    }
}; */
 

