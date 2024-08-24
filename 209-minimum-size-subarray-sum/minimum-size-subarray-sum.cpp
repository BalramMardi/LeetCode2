class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int j = 0 ;
        int curr = 0 ;
        int minSize = INT_MAX; 
        for(int i = 0 ;i < size(v) ; i++){  
            curr += v[i] ; 
            if(curr < target){
                continue ;
            }
            else if(curr >= target && j <= i){
                curr -= (v[j] + v[i]) ;
                minSize = min(minSize, i - j + 1) ;
                j++;i--;
            }
        }
        return (minSize != INT_MAX) ? minSize : 0;
    }
};