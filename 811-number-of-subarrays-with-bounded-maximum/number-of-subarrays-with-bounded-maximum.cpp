class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count = 0, lastValid = -1, lastBreak = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= left && nums[i] <= right) {
                lastValid = i;
            }
            if (nums[i] > right) {
                lastBreak = i;
                lastValid = -1;
            }
            if (lastValid != -1) {
                count += lastValid - lastBreak;
            }
        }

        return count;
    }
};


/* class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long start=0;
        long long end=0;

        long long n=nums.size();
        long long ans=0;
        long long prev=0;

        while(end<n){
            if(left<=nums[end] and nums[end]<=right){
                prev=end-start+1;
                ans+=prev;

            }
            else if(nums[end]<left){
                ans+=prev;
            }
            else{
                start=end+1;
                prev=0;
            }
            end++;
        }
        return ans;
    }
}; */