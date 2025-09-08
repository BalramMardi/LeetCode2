#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int x : arr) mp[x]++;

        priority_queue<int> pq;
        for (auto& it : mp) {
            pq.push(it.second);
        }

        int removed = 0, count = 0;
        while (removed < n / 2) {
            removed += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};
