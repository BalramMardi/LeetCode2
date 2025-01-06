class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = *max_element(nums2.begin(), nums2.end()); 
        vector<int> vec(n+1,-1);
        stack<int> st;

        for(int i=0;i<nums2.size();i++){
            while(st.size() and nums2[st.top()] < nums2[i]){
                int stackTop = st.top();
                st.pop();
                vec[nums2[stackTop]] = nums2[i];
            }
            st.push(i);
        }

        vector<int> ans;

        for(int it : nums1){
            ans.push_back(vec[it]);
        }

        return ans;

    }
};