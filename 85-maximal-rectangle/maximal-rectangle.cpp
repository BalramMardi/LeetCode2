class Solution {
public:

    int maxArea(vector<int>&height){
        int n = height.size();
        stack<int> st;
        int maxa = 0;
        for(int i=0;i<=n;i++){
            int curr = (i==n) ? 0 : height[i];
            while(st.size() and curr < height[st.top()]){
                int currh =  height[st.top()];
                st.pop();
                int width = (st.empty()) ? i : (i-st.top()-1);
                maxa = max(maxa, width*currh);
            }

            st.push(i);
        }
        return maxa;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int row =matrix.size();
        int col =matrix[0].size();
        int maxR = 0;
        vector<int> height(col,0);
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                height[j] = (matrix[i][j] == '1') ? height[j]+1: 0;
            }
            maxR = max(maxR, maxArea(height));
        }
        return maxR;
    }
};