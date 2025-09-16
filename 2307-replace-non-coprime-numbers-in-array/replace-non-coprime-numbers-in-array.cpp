class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back();
                int b = st[st.size() - 2];
                int g = gcd(a, b);
                if (g > 1) {
                    st.pop_back();
                    st.pop_back();
                    long long l = (1LL * a / g) * b; // lcm
                    st.push_back((int)l);
                } else break;
            }
        }
        return st;
    }
};