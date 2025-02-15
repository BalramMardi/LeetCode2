class Solution {
public:
    bool canPartition(string& numStr, int index, int currentSum, int target) {
        if (index == numStr.length()) {
            return (currentSum == target);
        }

        int num = 0;

        for (int i = index; i < numStr.length(); i++) {
            num = num * 10 + (numStr[i] - '0'); 

            if (canPartition(numStr, i + 1, currentSum + num, target)) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;

        for (int x = 1; x <= n; x++) {
            int square = x * x;
            string sqStr = to_string(square);

            if (canPartition(sqStr, 0, 0, x)) {
                sum += square;
            }
        }

        return sum;
    }
};