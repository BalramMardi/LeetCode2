class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> newnums(n*2);
        for (int i = 0; i < n; i++) {
            newnums[i] = nums[i];
            newnums[i + n] = nums[i];
        }

        stack<int> st;
        vector<int> ans(2*n,-1);

        for(int i=0;i<2*n;i++){
            while(st.size() and newnums[st.top()] < newnums[i]){
                int stackTop = st.top();
                st.pop();
                ans[stackTop] = newnums[i];
            }
            st.push(i);
        }

        vector<int> res;

        for(int i=0;i<n;i++){
            res.push_back(ans[i]);
        }

        return res;

    }
};