class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int alwaysHappy = 0;

        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                alwaysHappy += customers[i];
                customers[i] = 0;
            }
        }

        int extraHappy = 0;
        int maxExtraHappy = 0;

        for (int i = 0; i < n; ++i) {
            extraHappy += customers[i];
            if (i >= X) {
                extraHappy -= customers[i - X];
            }
            maxExtraHappy = max(maxExtraHappy, extraHappy);
        }

        return alwaysHappy + maxExtraHappy;
    }
};


/* class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int currSum = 0;

        for (int i = 0; i < minutes; i++) {
            currSum += customers[i] * grumpy[i];
        }

        int maxSum = currSum;

        for (int i = minutes; i < n; i++) {

            currSum += customers[i] * grumpy[i];
            currSum -= customers[i - minutes] * grumpy[i - minutes];

            maxSum = max(maxSum, currSum);
        }

        int totalCustomers = maxSum;

        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        return totalCustomers;
    }
}; */