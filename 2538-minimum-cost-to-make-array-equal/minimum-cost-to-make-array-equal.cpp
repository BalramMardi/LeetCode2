class Solution {
public:

    typedef long long ll;

    ll getCost(vector<int>& nums, vector<int>& cost, int target) {
        ll result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += (ll) abs(nums[i] - target) * cost[i];
        }
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());

        ll answer = INT_MAX;


        while(low <= high){

            int mid = low + (high - low)/2;
            int nextmid = mid+1;

            ll cost1 = getCost(nums,cost,mid);
            ll cost2 = getCost(nums,cost,mid+1);
            answer = min(cost1, cost2);


            if(cost1 > cost2){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return answer == INT_MAX ? 0 : answer;


    }
};