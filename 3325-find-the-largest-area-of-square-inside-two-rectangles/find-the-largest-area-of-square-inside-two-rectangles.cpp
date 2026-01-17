class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n=bottomLeft.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int bx = bottomLeft[i][0];
            int by = bottomLeft[i][1];
            int tx = topRight[i][0];
            int ty = topRight[i][1];
            for(int j=i+1;j<n;j++){
                int nbx = bottomLeft[j][0];
                int nby = bottomLeft[j][1];
                int ntx = topRight[j][0];
                int nty = topRight[j][1];

                int w = min(tx,ntx) - max(bx,nbx);
                int h = min(ty,nty) - max(by,nby);
                ans = max(ans, min(w,h));
            }
        }

        return 1LL*ans*ans;
    }
};