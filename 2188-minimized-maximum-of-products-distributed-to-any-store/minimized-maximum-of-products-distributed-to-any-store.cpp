class Solution {
public:
    bool canDistribute(vector<int>& products, int n, int mid) {
        int storeCount = 0;
        for (int product : products) {
            storeCount += (product + mid - 1) / mid;
        }
        return storeCount <= n;
    }



    int minimizedMaximum(int n, vector<int>& arr) {
        int low = 1;
        int high = 100000;
        int ans=high;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(canDistribute(arr,n,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};