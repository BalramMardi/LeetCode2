class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1;
        int score = 0, maxScore = 0;

        while (i <= j) {
            if (power >= tokens[i]) {
                // Gain score by using the smallest token
                power -= tokens[i];
                score++;
                i++;
                maxScore = max(maxScore, score);
            } else if (score > 0) {
                // Gain power by using the largest token, but lose score
                power += tokens[j];
                score--;
                j--;
            } else {
                // If neither can gain score nor gain power, break the loop
                break;
            }
        }

        return maxScore;
    }
};
