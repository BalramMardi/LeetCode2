#include <string>
#include <vector>
#include <queue>
#include <functional>

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a < b;
            }
            return a.size() < b.size();
        };
        
        priority_queue<string, vector<string>, decltype(comp)> pq(comp);
        
        for (const string& num : nums) {
            pq.push(num);
        }

        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }

        return pq.top();
    }
};
