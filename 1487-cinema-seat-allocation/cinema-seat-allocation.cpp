class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (auto& seat : reservedSeats) {
            reserved[seat[0]] |= (1 << seat[1]);
        }
        
        int max_families = 2 * n;
        
        for (auto& [row, mask] : reserved) {
            bool left = !(mask & 60);
            bool right = !(mask & 960);
            bool middle = !(mask & 240);
            
            if (left && right) {
                continue;
            } else if (left || right || middle) {
                max_families -= 1;
            } else {
                max_families -= 2;
            }
        }
        
        return max_families;
    }
};