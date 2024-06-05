class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int n = nums.size(), flag = true;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1])
            {
                if(flag) 
                {
                    flag = false;
                    if(i+2 < n)
                    {
                        if(nums[i] < nums[i+2]) nums[i+1] = nums[i];
                        else nums[i] = nums[i+1];
                    }
                    else nums[i+1] = nums[i];
                }
                else return false;
            }
        }
        vector<int>temp = nums;
        sort(nums.begin(), nums.end());
        return nums == temp;
    }
};