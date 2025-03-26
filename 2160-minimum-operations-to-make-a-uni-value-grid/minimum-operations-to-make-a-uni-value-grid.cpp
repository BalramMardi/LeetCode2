class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());

        int mid= nums[nums.size()/2];
        int res=0;
        for(int num : nums){

            if(num % x != mid % x) return -1;

            res += abs(mid - num)/x;
        }

        return res;
    }
};