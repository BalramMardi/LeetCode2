class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> mp;

        int x1 = INT_MAX;
        int y1 = INT_MAX;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        long long area = 0;
        for (auto& rec : rectangles) {
            int x1curr = rec[0];
            int y1curr = rec[1];
            int x2curr = rec[2];
            int y2curr = rec[3];

            area += 1LL * (x2curr - x1curr) * (y2curr - y1curr);

            x1 = min(x1curr, x1);
            y1 = min(y1curr, y1);
            x2 = max(x2curr, x2);
            y2 = max(y2curr, y2);

            mp[to_string(x1curr) + "," + to_string(y1curr)]++;
            mp[to_string(x1curr) + "," + to_string(y2curr)]++;
            mp[to_string(x2curr) + "," + to_string(y1curr)]++;
            mp[to_string(x2curr) + "," + to_string(y2curr)]++;
        }

        if (mp[to_string(x1) + "," + to_string(y1)] != 1 or
            mp[to_string(x1) + "," + to_string(y2)] != 1 or
            mp[to_string(x2) + "," + to_string(y1)] != 1 or
            mp[to_string(x2) + "," + to_string(y2)] != 1) {
            return false;
        }

        for (auto& [point, count] : mp) {

            if (count % 2 == 1 &&
                (point != to_string(x1) + "," + to_string(y1)) &&
                (point != to_string(x1) + "," + to_string(y2)) &&
                (point != to_string(x2) + "," + to_string(y1)) &&
                (point != to_string(x2) + "," + to_string(y2))) {
                return false;
            }
        }

        long long expectedArea = 1LL * (x2 - x1) * (y2 - y1);
        if (area != expectedArea) return false;

        return true;
    }
};