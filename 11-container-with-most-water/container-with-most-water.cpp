#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        long res=0;
        int li=0;
        int ri=height.size()-1;

        while(li<ri){
            int left = height[li];
            int right = height[ri];

            long area = min(left,right)*(ri-li);
            res = max(area,res);

            if(left < right){
                li++;
            }
            else{
                ri--;
            }
        }

        return res;
    }
};

