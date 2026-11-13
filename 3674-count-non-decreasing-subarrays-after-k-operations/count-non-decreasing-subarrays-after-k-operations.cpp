class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        deque<pair<long long, long long>> dq;
        long long sum_max = 0;
        long long sum_nums = 0;
        int r = n - 1;
        
        for(int l = n - 1; l >= 0; --l) {
            long long val = nums[l];
            long long cnt = 1;
            sum_nums += val;
            
            while(!dq.empty() && dq.front().first <= val) {
                cnt += dq.front().second;
                sum_max -= dq.front().first * dq.front().second;
                dq.pop_front();
            }
            
            dq.push_front({val, cnt});
            sum_max += val * cnt;
            
            while(sum_max - sum_nums > k) {
                sum_nums -= nums[r];
                sum_max -= dq.back().first;
                dq.back().second--;
                
                if(dq.back().second == 0) {
                    dq.pop_back();
                }
                r--;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};