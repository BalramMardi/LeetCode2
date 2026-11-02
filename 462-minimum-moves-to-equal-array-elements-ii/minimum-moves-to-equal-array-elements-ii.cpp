class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long mini_moves = LLONG_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            long long curr_moves = 0;
            for (int j = 0; j < nums.size(); ++j) {
                curr_moves += abs(nums[i] - nums[j]);
            }
            mini_moves = min(mini_moves, curr_moves);
        }
        
        return mini_moves;
    }
};