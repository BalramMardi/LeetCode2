class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s1, s2;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        for (int i = 0; i < n; ++i) {
            
            while (!pq.empty() && pq.top().first < nums[i]) {
                res[pq.top().second] = nums[i];
                pq.pop();
            }

            
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                s2.push(s1.top());
                s1.pop();
            }

           
            while (!s2.empty()) {
                pq.push({nums[s2.top()], s2.top()});
                s2.pop();
            }

            s1.push(i);
        }

        return res;
    }
};