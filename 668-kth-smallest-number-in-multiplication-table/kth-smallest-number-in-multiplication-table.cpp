class Solution {
public:

    bool solve(int mid,int m, int n, int k){

        int count = 0;

        for(int i=1;i<=m;i++){

            count += min( mid/i , n);
        }

        if(count >= k){
            return true;
        }
        else{
            return false;
        }
    }


    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;

        int ans;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(solve(mid , m , n , k)){
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};