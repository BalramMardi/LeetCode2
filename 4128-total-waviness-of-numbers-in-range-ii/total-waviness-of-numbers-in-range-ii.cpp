class Solution {
    string S;
    pair<long long, long long> memo[20][11][11][2][2];
    bool visited[20][11][11][2][2];

    pair<long long, long long> solve(int idx, int prev2, int prev, bool is_less, bool is_started) {
        if (idx == (int)S.length()) {
            return {1, 0};
        }
        if (visited[idx][prev2 + 1][prev + 1][is_less][is_started]) {
            return memo[idx][prev2 + 1][prev + 1][is_less][is_started];
        }
        
        long long total_cnt = 0;
        long long total_wave = 0;
        int limit = is_less ? 9 : (S[idx] - '0');
        
        for (int d = 0; d <= limit; ++d) {
            bool nxt_less = is_less || (d < limit);
            bool nxt_started = is_started || (d > 0);
            int nxt_prev2 = -1;
            int nxt_prev = -1;
            
            if (nxt_started) {
                if (is_started) {
                    nxt_prev2 = prev;
                    nxt_prev = d;
                } else {
                    nxt_prev2 = -1;
                    nxt_prev = d;
                }
            }
            
            auto [cnt, wave] = solve(idx + 1, nxt_prev2, nxt_prev, nxt_less, nxt_started);
            
            long long is_wave = 0;
            if (is_started && prev2 != -1) {
                if (prev > prev2 && prev > d) is_wave = 1;
                if (prev < prev2 && prev < d) is_wave = 1;
            }
            
            total_cnt += cnt;
            total_wave += wave + cnt * is_wave;
        }
        
        visited[idx][prev2 + 1][prev + 1][is_less][is_started] = true;
        return memo[idx][prev2 + 1][prev + 1][is_less][is_started] = {total_cnt, total_wave};
    }

    long long countWaviness(long long x) {
        if (x < 0) return 0;
        S = to_string(x);
        memset(visited, 0, sizeof(visited));
        return solve(0, -1, -1, false, false).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return countWaviness(num2) - countWaviness(num1 - 1);
    }
};