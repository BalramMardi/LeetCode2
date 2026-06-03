class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minLandEnd = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }

        int minWaterEnd = INT_MAX;
        for (int j = 0; j < m; ++j) {
            minWaterEnd = min(minWaterEnd, waterStartTime[j] + waterDuration[j]);
        }

        int mini = INT_MAX;

        for (int j = 0; j < m; ++j) {
            int startWater = max(minLandEnd, waterStartTime[j]);
            mini = min(mini, startWater + waterDuration[j]);
        }

        for (int i = 0; i < n; ++i) {
            int startLand = max(minWaterEnd, landStartTime[i]);
            mini = min(mini, startLand + landDuration[i]);
        }

        return mini;
    }
};