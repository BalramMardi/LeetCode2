class Solution {
public:
    int digitCount(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n /= 10;
        }
        return count;
    }

    bool solve(const string& s) {
        int mid = s.size() / 2;
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < mid; i++) {
            leftSum += s[i] - '0';
        }
        for (int i = mid; i < s.size(); i++) {
            rightSum += s[i] - '0';
        }
        return leftSum == rightSum;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            int dc = digitCount(i);
            if (dc % 2 == 0) {
                string num = to_string(i);
                if (solve(num)) {
                    count++;
                }
            }
        }
        return count;
    }
};
