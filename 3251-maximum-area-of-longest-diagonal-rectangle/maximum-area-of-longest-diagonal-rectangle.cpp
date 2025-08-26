class Solution {
public:
    double diagonal(int l, int w) {
        return sqrt(1.0 * l * l + 1.0 * w * w);
    }

    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        double maxi = -1.0;
        int maxarea = 0;

        for (int i = 0; i < d.size(); i++) {
            int l = d[i][0];
            int w = d[i][1];
            int area = l * w;
            double diag = diagonal(l, w);

            if (diag > maxi) {
                maxi = diag;
                maxarea = area;
            } else if (abs(diag - maxi) < 1e-9) { 
                maxarea = max(maxarea, area);
            }
        }

        return maxarea;
    }
};
