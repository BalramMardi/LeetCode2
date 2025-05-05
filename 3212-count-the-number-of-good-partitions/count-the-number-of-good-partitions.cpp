


/* class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> last;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            last[nums[i]] = i;
        }

        int end = 0, cuts = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, last[nums[i]]);
            if (i == end) {
                cuts++;
            }
        }

        return cuts == 0 ? 1 : power(2, cuts - 1);
    }

    int power(int base, int exp) {
        long long result = 1;
        long long b = base;

        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }

        return result;
    }
};
 */

 class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        unordered_map<int, int> first, last;
        for (int i = 0; i < n; ++i) {
            if (!first.count(nums[i])) {
                first[nums[i]] = i;
            }
            last[nums[i]] = i;
        }

        vector<pair<int, int>> intervals;
        for (auto& [num, l] : first) {
            intervals.push_back({l, last[num]});
        }

     
        sort(intervals.begin(), intervals.end());

        int merged = 0;
        int curr_start = intervals[0].first;
        int curr_end = intervals[0].second;

        for (int i = 1; i < intervals.size(); ++i) {
            auto [s, e] = intervals[i];
            if (s > curr_end) {
                merged++;
                curr_start = s;
                curr_end = e;
            } else {
                curr_end = max(curr_end, e);
            }
        }

        merged++;

        long long res = 1;
        for (int i = 0; i < merged - 1; ++i) {
            res = (res * 2) % MOD;
        }

        return res;
    }
};
