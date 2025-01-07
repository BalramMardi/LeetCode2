class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            int pos = cars[i][0], speed = cars[i][1];

            while (!st.empty()) {
                int j = st.top();
                int nextPos = cars[j][0], nextSpeed = cars[j][1];

                
                if (speed <= nextSpeed || (ans[j] != -1 && (double)(nextPos - pos) / (speed - nextSpeed) >= ans[j])) {
                    st.pop();
                } else {
                    break;
                }
            }


            if (!st.empty()) {
                int j = st.top();
                ans[i] = (double)(cars[j][0] - pos) / (speed - cars[j][1]);
            }

            st.push(i); 
        }
        return ans;

    }
};