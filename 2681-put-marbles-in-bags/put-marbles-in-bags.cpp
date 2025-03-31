class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        
        priority_queue<long long> max_heap;
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        
        for (int i = 0; i < n - 1; i++) {
            long long sum = weights[i] + weights[i + 1];
            
           
            if (max_heap.size() < k - 1) {
                max_heap.push(sum);
            } else if (sum < max_heap.top()) {
                max_heap.pop();
                max_heap.push(sum);
            }
            
          
            if (min_heap.size() < k - 1) {
                min_heap.push(sum);
            } else if (sum > min_heap.top()) {
                min_heap.pop();
                min_heap.push(sum);
            }
        }
        
        long long min_sum = 0;
        while (!max_heap.empty()) {
            min_sum += max_heap.top();
            max_heap.pop();
        }
        
        long long max_sum = 0;
        while (!min_heap.empty()) {
            max_sum += min_heap.top();
            min_heap.pop();
        }
        
        return max_sum - min_sum;
    }
};

/* class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairWeights(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            pairWeights[i] += weights[i] + weights[i + 1];
        }

        sort(pairWeights.begin(), pairWeights.end());

        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += pairWeights[n - 2 - i] - pairWeights[i];
        }

        return answer;
    }
}; */