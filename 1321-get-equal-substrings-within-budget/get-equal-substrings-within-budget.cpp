class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int left = 0, right = 0;
        int totalCost = 0, maxLength = 0;

        while (right < n) {
            // Calculate the cost of the current character change
            totalCost += abs(t[right] - s[right]);

            // If the total cost exceeds maxCost, shrink the window from the left
            while (totalCost > maxCost) {
                totalCost -= abs(t[left] - s[left]);
                left++;
            }

            // Update the maximum length of the valid substring
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        
        return maxLength;
    }
};
