class Solution {
public:
    int halveArray(vector<int>& nums) {
        double s = accumulate(begin(nums), end(nums), 0.0), k = 0;
        int i = 0;
        priority_queue<double> pq;
        
        for (int num : nums)
            pq.push((double)num);

        while (s - k > s / 2) {
            double x = pq.top(); pq.pop();
            k += x / 2;
            pq.push(x / 2);     
            i++;
        }

        return i;
    }

};


/* class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxHeap;
        double totalSum = 0;

        for (int num : nums) {
            totalSum += num;
            maxHeap.push(num);
        }

        double reducedSum = 0;
        int operations = 0;

        while (reducedSum < totalSum / 2) {
            double largest = maxHeap.top();
            maxHeap.pop();

            double half = largest / 2.0;
            reducedSum += half;
            maxHeap.push(half);

            operations++;
        }

        return operations;
    }
};
 */