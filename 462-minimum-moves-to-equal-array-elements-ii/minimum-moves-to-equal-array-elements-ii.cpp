class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums[nums.size()/2];

        int sum=0;
        for(int num : nums){
            sum += abs(num - mid);
        }

        return sum;
    }
};