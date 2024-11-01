class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l=k,r=k;
        int sum;
        int currmin = nums[k];
        int result = nums[k];
        while(l>0 || r<nums.size()-1){
            int leftval= l>0 ? nums[l-1] : 0;
            int rightval= r<nums.size()-1 ? nums[r+1] : 0;

            if(leftval>rightval){
                l--;
                currmin = min(currmin,nums[l]);
            }
            else{
                r++;
                currmin = min(currmin,nums[r]);
            }

            result = max(result,currmin*(r-l+1));
            
        }

        return result;
        
    }
};