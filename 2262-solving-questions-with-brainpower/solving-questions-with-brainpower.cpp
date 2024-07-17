class Solution {
public:

    vector<long long> memo;

    long long solve(vector<vector<int>>& questions, int i) {
        if (i >= questions.size()) {
            return 0;
        }
        

        if (memo[i] != -1) {
            return memo[i];
        }
        
    
        long long take = questions[i][0] + solve(questions, i + questions[i][1] + 1);
        
        long long skip = solve(questions, i + 1);
        
        
        memo[i] = max(take, skip);
        return memo[i];
    }

    long long mostPoints(vector<vector<int>>& questions) {
   
        memo = vector<long long>(questions.size(), -1);
        return solve(questions, 0);
    }
};
