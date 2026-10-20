class Solution {
public:
    vector<int> getDivisors(int n) {
        vector<int> divisors;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                divisors.push_back(i);

                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }

        return divisors;
    }


    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for (int div : getDivisors(n)) {
            bool isDivSortable = true;
            int i = 0;
            int prevMax = INT_MIN;

            while (i < n) {
                vector<int> partition(
                    nums.begin() + i,
                    nums.begin() + i + div
                );

                vector<int> sortedPartition = partition;
                sort(sortedPartition.begin(), sortedPartition.end());

                if (prevMax > sortedPartition[0]) {
                    isDivSortable = false;
                    break;
                }

                int drops = 0;

                for (int j = 0; j < div; j++) {
                    if (partition[j] > partition[(j + 1) % div]) {
                        drops++;
                    }
                }

                if (drops > 1) {
                    isDivSortable = false;
                    break;
                }

                prevMax = sortedPartition.back();
                i += div;
            }

            if (isDivSortable) {
                res += div;
            }
        }

        return res;
    }
};