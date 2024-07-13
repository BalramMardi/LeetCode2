class Solution {
public:

    bool canPossible(vector<int> &wt,int days,int mid){
        int sum=0;
        int window=1;
        for(int i=0;i<wt.size();i++){
            sum += wt[i];
            if(mid < sum){
                window++;
                sum = wt[i];
            }
        }

        return window<=days;
    }




    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(canPossible(weights,days,mid)){
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