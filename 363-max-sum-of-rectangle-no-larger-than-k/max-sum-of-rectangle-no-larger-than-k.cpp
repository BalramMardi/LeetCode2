#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kadane(vector<int>& vec, int k) {
        int maxSum = INT_MIN;
        for (int start = 0; start < vec.size(); start++) {
            int sum = 0;
            for (int end = start; end < vec.size(); end++) {
                sum += vec[end];
                if (sum <= k) {
                    maxSum = max(maxSum, sum);
                }
            }
        }
        return maxSum;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < col; left++) {
            vector<int> vec(row, 0); 

            for (int right = left; right < col; right++) {
                for (int i = 0; i < row; i++) {
                    vec[i] += matrix[i][right];
                }

                maxSum = max(maxSum, kadane(vec, k));
                if (maxSum == k) return k; 
            }
        }

        return maxSum;
    }
};
