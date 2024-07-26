#define ll long long

class Solution {
public:
    ll memo[1000001][2];
    ll solve(vector<int>& nums,int idx,bool flag){
        if(idx >= nums.size()){
            return 0;
        }


        if(memo[idx][flag] != -1){
            return memo[idx][flag];
        }

        ll skip = solve(nums,idx+1,flag);

        ll val = nums[idx];

        if(!flag){
            val = -val;
        }

        ll take =val+solve(nums,idx+1,!flag);

        return  memo[idx][flag]= max(skip,take);

    }


    long long maxAlternatingSum(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return solve(nums,0,true);
    }
};