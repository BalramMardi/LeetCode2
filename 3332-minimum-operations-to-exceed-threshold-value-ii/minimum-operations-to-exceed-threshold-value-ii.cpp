class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;

        for(int num : nums){
            pq.push(num);
        }
        ll maxa = 0;
        ll mini = 0;
        int count = 0;
        while(pq.size() > 1){
            mini = pq.top();
            pq.pop();
            maxa = pq.top();
            pq.pop();
            if(mini >= k and maxa >=k){
                break;
            }
            ll sum = mini*2 + maxa;
            pq.push(sum);
            count++;
        }

        return count;
    }
};