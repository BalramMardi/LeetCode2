class Solution {
public:

    int solver(vector<int>& bloomDay, int k,int mid){

        int count=0,buquet=0;

        for(int i=0;i<bloomDay.size();i++){

            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                count=0;
            }

            if(count == k){
                buquet++;
                count = 0;
            }
        }

        return buquet;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = *max_element(bloomDay.begin(),bloomDay.end());

        int ans=-1;
        while(start <= end){
            int mid = start + (end - start)/2;

            if(solver(bloomDay, k, mid) >= m){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }

        return ans;
    }
};