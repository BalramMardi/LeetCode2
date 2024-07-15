class Solution {
public:

    bool canPossible(vector<int>& nums,int &k,int &mid){

        int count=1;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > mid){
                count++;
                sum= nums[i];
            }

        }
        return count <= k;
    }



    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canPossible(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};