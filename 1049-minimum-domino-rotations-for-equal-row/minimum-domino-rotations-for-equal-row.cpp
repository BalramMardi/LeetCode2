class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
         int n = tops.size(),i,j,k1=1,x1,k2,x2,ans;
        ans=n+10;
        for(i = 1; i <= 6; i++){
            k1 = 1,x1=0,k2=1,x2=0;
            for(j = 0; j < n; j++){
                if(tops[j]==i);
                else if(bottoms[j]==i){
                    x1++;
                }else{
                    k1 = 0;
                }
                if(bottoms[j]==i);
                else if(tops[j]==i){
                    x2++;
                }else{
                    k2 = 0;
                }
            }
            
            if(k1){
                ans = min({ans,x1});
            }if(k2){
                ans = min(ans,x2);
            }
        }
        return ans>n?-1:ans;;
    }
};