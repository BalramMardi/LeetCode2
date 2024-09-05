class Solution {
public:


static bool compareBalloons(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];  // Sort by end in ascending order
}
    int findMinArrowShots(vector<vector<int>>& points) {
         if (points.empty()) return 0;
    
    // Sort the balloons by their end points
    sort(points.begin(), points.end(), compareBalloons);
    
    int arrowCount = 1;  // At least one arrow is needed
    int lastArrowPosition = points[0][1];  // Place the first arrow at the end of the first balloon
    
    // Traverse through the sorted balloons
    for (const auto& balloon : points) {
        // If the current balloon starts after the last arrow position, shoot a new arrow
        if (balloon[0] > lastArrowPosition) {
            arrowCount++;  // Increment the arrow count
            lastArrowPosition = balloon[1];  // Update the position of the last arrow
        }
    }
    
    return arrowCount;
    }
};