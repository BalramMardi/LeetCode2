class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i=1,j=1;
        int maxx = 1;
        for(int k=0;k<arr.size()-1;k++){

            if(arr[k] > arr[k+1]){
                i = j+1;
                j=1;
            }
            else if(arr[k] < arr[k+1]){
                j=i+1;
                i=1;
            }
            else{
                i=1;
                j=1;
            }

            maxx = max({i,j,maxx});
        }

        return maxx;
    }
};