class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int max_len = 0;
        int zero_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zero_count++;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};


/* class Solution {
public:
    vector<int>arr;
    int n;
    bool check(int mid,int k){
        int cnt1 = 0;
        int cnt0 = 0;
        int left = 0,right = 0;
        while(right < mid){
            if(arr[right] == 1){
                cnt1++;
            }
            else{
                cnt0++;
            }
            right++;
        }
        if(cnt0 <= k) return 1;
        while(right < n){
            if(cnt0 <= k) return 1;
            if(arr[left] == 0) cnt0--;
            else cnt1--;
            left++;
            if(arr[right] == 0) cnt0++;
            else cnt1++;
            right++;
        }
        if(cnt0 <= k) return 1;
        return 0;
    }
    int longestOnes(vector<int>& nums, int k) {
        arr = nums;
        n = arr.size();
        int ans = 0;
        int beg = 0;
        int end = n;
        while(beg <= end){
            int mid = beg + (end - beg)/2;
            if(check(mid,k) == 1){
                ans = mid;
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
}; */