class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int mini = *min_element(nums.begin(),nums.end());
        for(int num : nums){
            moves += (num - mini);
        }
        return moves;
    }
};