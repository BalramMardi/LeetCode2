class Solution {
public:

    bool canPossible(vector<int>&nums,int p,int mid){
        int count=0;
        int check =0;
        for(int i=1;i<nums.size();i++){
            if(check){
                check=0;
                continue;
            }
            if(nums[i]-nums[i-1] <= mid){
                count++;
                check=1;
            }
        }

        return count>=p;
    }


    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1]- nums[0];

        int ans=0;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(canPossible(nums,p,mid)){
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};