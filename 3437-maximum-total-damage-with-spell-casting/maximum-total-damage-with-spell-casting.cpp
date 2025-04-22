class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0;

      
        unordered_map<int, int> countMap;
        for (int num : power) {
            countMap[num]++;
        }

    
        vector<int> uniquePowers;
        for (auto& entry : countMap) {
            uniquePowers.push_back(entry.first);
        }
        sort(uniquePowers.begin(), uniquePowers.end());

        int n = uniquePowers.size();
        vector<long long> dp(n, 0);
        vector<long long> damage(n, 0);

     
        for (int i = 0; i < n; ++i) {
            damage[i] = (long long)uniquePowers[i] * countMap[uniquePowers[i]];
        }

        dp[0] = damage[0]; 

        for (int i = 1; i < n; ++i) {
            // Option 1: Do not take the current power
            long long option1 = dp[i - 1];

            // Option 2: Take the current power, find the largest j where uniquePowers[j] < uniquePowers[i] - 2
            long long option2 = damage[i];
            int left = 0, right = i - 1;
            int j = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (uniquePowers[mid] < uniquePowers[i] - 2) {
                    j = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (j != -1) {
                option2 += dp[j];
            }

            dp[i] = max(option1, option2);
        }

        return dp[n - 1];
    }
};


/* class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty())
            return 0;

        unordered_map<int, int> count;
        for (int p : power) {
            count[p]++;
        }

        vector<int> uniquePowers;
        for (auto& pair : count) {
            uniquePowers.push_back(pair.first);
        }
        sort(uniquePowers.begin(), uniquePowers.end());

        int n = uniquePowers.size();
        if (n == 0)
            return 0;

        vector<long long> dp(n, 0);
        dp[0] = (long long)uniquePowers[0] * count[uniquePowers[0]];

        for (int i = 1; i < n; ++i) {
            long long current_sum = (long long)uniquePowers[i] * count[uniquePowers[i]];
            int target = uniquePowers[i] - 3;

           
            auto it = upper_bound(uniquePowers.begin(),uniquePowers.begin() + i, target);
            if (it != uniquePowers.begin()) {
                int j = distance(uniquePowers.begin(), it) - 1;
                current_sum += dp[j];
            }

            dp[i] = max(dp[i - 1], current_sum);
        }

        return dp.back();
    }
}; */