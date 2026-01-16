

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> vGaps;
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i + 1; j < vFences.size(); ++j) {
                vGaps.insert(vFences[j] - vFences[i]);
            }
        }

        long long maxLen = -1;
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i + 1; j < hFences.size(); ++j) {
                int hGap = hFences[j] - hFences[i];
                if (vGaps.count(hGap)) {
                    maxLen = max(maxLen, (long long)hGap);
                }
            }
        }

        if (maxLen == -1) return -1;
        
        long long mod = 1e9 + 7;
        return (maxLen * maxLen) % mod;
    }
};