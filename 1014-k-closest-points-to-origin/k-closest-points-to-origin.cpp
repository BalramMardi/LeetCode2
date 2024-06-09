#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            int first_digit = points[i][0] * points[i][0];
            int second_digit = points[i][1] * points[i][1];
            int distance_squared = first_digit + second_digit;
            pq.push({distance_squared, i});
        }

        for (int i = 0; i < k; i++) {
            int index = pq.top().second;
            pq.pop();
            ans.push_back(points[index]);
        }

        return ans;
    }
};
