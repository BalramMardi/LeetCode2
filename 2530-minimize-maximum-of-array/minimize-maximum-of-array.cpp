class Solution {
public:
    
    bool isValid(vector<int> &nums, int mid_max, int n) {
        
        vector<long long> arr(begin(nums), end(nums));
        
        for(int i = 0; i<n-1; i++) {
            
            if(arr[i] > mid_max)
                return false;
            
            long long buffer = mid_max - arr[i];
            
            arr[i+1] = arr[i+1] - buffer;   
            
        }
        
        return arr[n-1] <= mid_max;
        
    }

    
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        
        int maxL = 0;
        int maxR = *max_element(begin(nums), end(nums));
        
        int result;
        
        while(maxL <= maxR) {
            
            int mid_max = maxL + (maxR-maxL)/2;
            
            if(isValid(nums, mid_max, n)) {
                result = mid_max;
                maxR   = mid_max-1;
            } else {
                maxL = mid_max+1;
            }
            
        }
        
        return result;
    }

    
};



/* int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long prefix_sum = 0;
        int max_val = 0;
        
        for (int i = 0; i < n; ++i) {
            prefix_sum += nums[i];
            int current_ceil = (prefix_sum + i) / (i + 1); 
            max_val = max(max_val, current_ceil);
        }
        
        return max_val;

} */