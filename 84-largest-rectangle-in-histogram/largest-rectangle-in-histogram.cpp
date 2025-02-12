class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxA = 0;
        for(int i=0;i<=n;i++){
            int curr= (i==n) ? 0 : heights[i];
            while(st.size() and curr < heights[st.top()]){
                int height =  heights[st.top()];
                st.pop();
                int width = (st.empty()) ? (i) : (i-st.top()-1);
                maxA = max(maxA , height*width);
            }
            st.push(i);
        }
        return maxA;
    }
};