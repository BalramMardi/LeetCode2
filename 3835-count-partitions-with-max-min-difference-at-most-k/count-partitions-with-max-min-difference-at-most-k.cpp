class Solution {
public:
    long long MOD = 1e9 + 7;

    int countPartitions(vector<int> &nums, int k)
    {
        int len = nums.size(), L = 0;

        vector<long long> x(len + 1), y(len + 2);

        x[0] = 1;
        y[1] = 1;

        deque<int> maxQ, minQ;

        for (int i = 1; i <= len; ++i)
        {
            int j = i - 1;

            while (!minQ.empty() && nums[minQ.back()] >= nums[j])
                minQ.pop_back();
            minQ.push_back(j);

            while (!maxQ.empty() && nums[maxQ.back()] <= nums[j])
                maxQ.pop_back();
            maxQ.push_back(j);

            while ((long long)nums[maxQ.front()] - nums[minQ.front()] > k)
            {
                ++L;
                if (maxQ.front() < L)
                    maxQ.pop_front();

                if (minQ.front() < L)
                    minQ.pop_front();
            }

            long long s = (y[i] - y[L] + MOD) % MOD;

            x[i] = s;

            y[i + 1] = (y[i] + x[i]) % MOD;
        }

        return x[len];
    }
};