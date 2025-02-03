#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        priority_queue<int> maxHeap; // Stores the smaller half
        priority_queue<int, vector<int>, greater<int>> minHeap; // Stores the larger half
        unordered_map<int, int> hashTable; // To keep track of invalid numbers

        int i = 0;
        while (i < k) {
            maxHeap.push(nums[i++]);
        }
        for (int j = 0; j < k / 2; ++j) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        while (true) {
            // Get the median of the current window
            if (k % 2 == 1) {
                result.push_back(maxHeap.top());
            } else {
                result.push_back(((double)maxHeap.top() + (double)minHeap.top()) / 2.0);
            }

            if (i >= nums.size()) break;

            int outNum = nums[i - k]; // Number to be removed from the window
            int inNum = nums[i++];    // Number to be added to the window
            int balance = 0;          // Balance factor to maintain heap sizes

            // Remove outNum from the heaps
            if (outNum <= maxHeap.top()) {
                --balance;
                if (outNum == maxHeap.top()) {
                    maxHeap.pop();
                } else {
                    ++hashTable[outNum];
                }
            } else {
                ++balance;
                if (outNum == minHeap.top()) {
                    minHeap.pop();
                } else {
                    ++hashTable[outNum];
                }
            }

            // Add inNum to the heaps
            if (!maxHeap.empty() && inNum <= maxHeap.top()) {
                ++balance;
                maxHeap.push(inNum);
            } else {
                --balance;
                minHeap.push(inNum);
            }

            // Rebalance the heaps
            if (balance < 0) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else if (balance > 0) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            // Remove invalid numbers at the top of the heaps
            while (!maxHeap.empty() && hashTable[maxHeap.top()] > 0) {
                --hashTable[maxHeap.top()];
                maxHeap.pop();
            }
            while (!minHeap.empty() && hashTable[minHeap.top()] > 0) {
                --hashTable[minHeap.top()];
                minHeap.pop();
            }
        }

        return result;
    }
};

