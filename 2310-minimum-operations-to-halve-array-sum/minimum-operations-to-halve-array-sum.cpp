class Solution {
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
