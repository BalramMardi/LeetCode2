

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue <int> pq;
        int minimum = INT_MAX;
        for(auto i : nums) {
            if(i & 1)
                i *= 2;
            minimum = min(minimum, i);
            pq.push(i);
        }
        int res = INT_MAX;
        while(pq.top() % 2 == 0) {
            int val = pq.top();
            res = min(res, val - minimum);
            minimum = min(val/2, minimum);
            pq.pop();
            pq.push(val/2);
        }
        return min(res, pq.top() - minimum);
    }
};
