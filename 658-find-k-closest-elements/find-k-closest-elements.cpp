class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;

        for (int num : arr) {
            maxHeap.push({abs(num - x), num});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        vector<int> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};


/* class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int L = 0, R = size(arr)-1;
        while (R - L >= k)
        { 
            if (x - arr[L] <= arr[R] - x) 
                {
                    R--;
                }
            else L++;
        }
        return vector<int>(begin(arr) + L, begin(arr) + R + 1);
    }
}; */