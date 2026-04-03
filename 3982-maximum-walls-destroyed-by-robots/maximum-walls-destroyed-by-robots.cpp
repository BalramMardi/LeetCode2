class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<long long, long long>> rob(n);
        for(int i = 0; i < n; ++i) {
            rob[i] = {robots[i], distance[i]};
        }
        sort(rob.begin(), rob.end());
        sort(walls.begin(), walls.end());
        
        vector<long long> w;
        int base_destroyed = 0;
        int r_idx = 0;
        for(long long wall : walls) {
            while(r_idx < n && rob[r_idx].first < wall) {
                r_idx++;
            }
            if(r_idx < n && rob[r_idx].first == wall) {
                base_destroyed++;
            } else {
                w.push_back(wall);
            }
        }
        
        auto W = [&](long long L, long long R) -> int {
            if(L > R) return 0;
            auto it1 = lower_bound(w.begin(), w.end(), L);
            auto it2 = upper_bound(w.begin(), w.end(), R);
            return it2 - it1;
        };
        
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = W(rob[0].first - rob[0].second, rob[0].first - 1);
        dp[0][1] = 0;
        
        for(int i = 1; i < n; ++i) {
            long long A = rob[i-1].first;
            long long d_A = rob[i-1].second;
            long long B = rob[i].first;
            long long d_B = rob[i].second;
            
            int w_LL = W(max(A + 1, B - d_B), B - 1);
            
            long long R_A = min(B - 1, A + d_A);
            long long L_B = max(A + 1, B - d_B);
            int w_RL = 0;
            if(R_A < L_B) {
                w_RL = W(A + 1, R_A) + W(L_B, B - 1);
            } else {
                w_RL = W(A + 1, B - 1);
            }
            
            int w_LR = 0;
            int w_RR = W(A + 1, min(B - 1, A + d_A));
            
            dp[i][0] = max(dp[i-1][0] + w_LL, dp[i-1][1] + w_RL);
            dp[i][1] = max(dp[i-1][0] + w_LR, dp[i-1][1] + w_RR);
        }
        
        long long ans = base_destroyed + max(dp[n-1][0], dp[n-1][1] + W(rob[n-1].first + 1, rob[n-1].first + rob[n-1].second));
        return ans;
    }
};