class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> ratioCount;
        
   
        for (const auto& rectangle : rectangles) {
            double ratio = static_cast<double>(rectangle[0]) / rectangle[1];
            ratioCount[ratio]++;
        }
        
        long long totalPairs = 0;
        
      
        for (const auto& entry : ratioCount) {
            long long count = entry.second;
            if (count > 1) {
                totalPairs += (count * (count - 1)) / 2;
            }
        }
        
        return totalPairs;
    }
};