class Solution {
public:
    bool canMakeSquare(vector<int>& matchsticks, vector<int>& sides, int index,
                       int target) {
        if (index == matchsticks.size()) {
            // Check if all sides are equal to the target
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }

        // Try to place the current matchstick on any of the 4 sides
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (canMakeSquare(matchsticks, sides, index + 1, target)) {
                    return true;
                }
                sides[i] -= matchsticks[index]; // Backtrack
            }

            // Optimization: If the current side is still zero after trying,
            // don't attempt to put more on it
            if (sides[i] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4)
            return false;

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;

        int target = sum / 4;
        sort(matchsticks.rbegin(),
             matchsticks.rend()); // Sort in descending order

        vector<int> sides(4, 0);
        return canMakeSquare(matchsticks, sides, 0, target);
    }
};