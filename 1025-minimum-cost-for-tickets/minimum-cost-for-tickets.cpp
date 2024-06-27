class Solution {
public:
    int minCost(vector<int>& days, vector<int>& costs, int dayIndex,
                vector<int>& memo) {
        if (dayIndex >= days.size()) {
            return 0;
        }

        if (memo[dayIndex] != -1) {
            return memo[dayIndex];
        }

        // Cost of buying a 1-day ticket
        int cost1 = costs[0] + minCost(days, costs, dayIndex + 1, memo);

        // Find the index for the next day after the current 7-day ticket
        // expires
        int nextIndex = dayIndex;
        while (nextIndex < days.size() &&
               days[nextIndex] < days[dayIndex] + 7) {
            nextIndex++;
        }
        int cost7 = costs[1] + minCost(days, costs, nextIndex, memo);

        // Find the index for the next day after the current 30-day ticket
        // expires
        nextIndex = dayIndex;
        while (nextIndex < days.size() &&
               days[nextIndex] < days[dayIndex] + 30) {
            nextIndex++;
        }
        int cost30 = costs[2] + minCost(days, costs, nextIndex, memo);

        // Store the result in the memo vector and return the minimum cost
        memo[dayIndex] = min({cost1, cost7, cost30});
        return memo[dayIndex];
    }

    // Function to initiate the recursive calculation
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        return minCost(days, costs, 0, memo);
    }
};