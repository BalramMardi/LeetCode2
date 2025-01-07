class Solution {
public:
    int carFleet(int ta, vector<int>& po, vector<int>& sp) {
        int n=po.size();
        vector<pair<int,double>> vec;

        for(int i=0;i<n;i++){
            double time = double(ta - po[i])/sp[i];
            vec.push_back({po[i],time});
        }

        sort(vec.rbegin(),vec.rend());

        stack<double> st;

        for(int i=0;i<n;i++){
            double curr = vec[i].second;
            if(st.empty() or st.top() < curr){
                st.push(curr);
            }
        }

        int len = st.size();

        return len;
    }
};