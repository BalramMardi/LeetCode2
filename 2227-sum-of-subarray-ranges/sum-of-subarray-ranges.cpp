class Solution {
public:

    long long minans(vector<int>& vec){
        int n=vec.size();
        vector<int> leftmin(n), rightmin(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && vec[s.top()] >= vec[i]) {
                s.pop();
            }
            leftmin[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && vec[s.top()] > vec[i]) {
                s.pop();
            }
            rightmin[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        long long ansmin = 0;
        for (int i = 0; i < n; i++) {

            ansmin += (1LL * vec[i] * leftmin[i] * rightmin[i]);
        }
        return ansmin;
    }

    long long maxans(vector<int>& vec){
        int n=vec.size();
        stack<int> st;
        vector<int> leftmax(n), rightmax(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vec[st.top()] <= vec[i]) {
                st.pop();
            }

            leftmax[i] = st.empty() ? i + 1 : i - st.top();

            st.push(i);
        }

        while (st.size())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && vec[st.top()] < vec[i]) {
                st.pop();
            }

            rightmax[i] = st.empty() ? n - i : st.top() - i;

            st.push(i);
        }

        long long ansmax = 0;

        for (int i = 0; i < n; i++) {
            ansmax += (1LL * leftmax[i] * rightmax[i] * vec[i]);
        }

        return ansmax;
    }


    long long subArrayRanges(vector<int>& nums) {
        return maxans(nums)-minans(nums);
    }
};