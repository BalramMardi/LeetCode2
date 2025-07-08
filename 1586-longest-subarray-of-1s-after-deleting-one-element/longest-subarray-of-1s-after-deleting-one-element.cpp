class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int zero=0;

        int left=0;

        int maxi = 0;

        for(int right=0;right<n;right++){

            if(nums[right]==0){
                zero++;
            }

            while(zero > 1){
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }

            maxi = max(maxi, right-left);
        }

        return maxi;
        
    }
};


/* class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        int maxx=0;
        int backup=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                maxx = max(maxx,count);
                count-=backup;
                backup=count;
            }
        }
        maxx = max(maxx,count);
        return maxx == nums.size() ? maxx-1 : maxx;
        
    }
}; */