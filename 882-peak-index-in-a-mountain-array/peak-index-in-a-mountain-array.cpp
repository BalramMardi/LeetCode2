class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1; 
            } else {
                high = mid;  
            }
        }
        
        return low; 
    }
};



/* class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        int n=nums.size();
        while(low <= high){
            int mid = low+(high-low)/2;

            if(mid>0 && nums[mid]<nums[mid-1]){
                high = mid-1;
            }
            else if(mid<n-1 && nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                return mid;
            }
        }

        return high;
    }
}; */