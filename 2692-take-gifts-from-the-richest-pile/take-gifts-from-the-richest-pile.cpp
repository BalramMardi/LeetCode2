class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq(gifts.begin(), gifts.end());
        while(k-- && !pq.empty()) {
            long long x = pq.top(); pq.pop();
            long long y = (long long)floor(sqrt(x));
            pq.push(y);
        }
        long long sum = 0;
        while(!pq.empty()) {
            sum += pq.top(); pq.pop();
        }
        return sum;
    }
};