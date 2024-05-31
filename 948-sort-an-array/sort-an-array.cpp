class Solution {
public:
    void merger(vector<int>& nums,int l,int m,int h){
        int n1 = m-l+1;
        int n2 = h-m;
        vector<int> Left(n1);
        vector<int> Right(n2);

        int k=l;
        for(int i=0;i<n1;i++){
            Left[i]=nums[k];
            k++;
        }
        for(int i=0;i<n2;i++){
            Right[i]=nums[k];
            k++;
        }

        int i=0;
        int j=0;
        k=l;

        while(i<n1 and j<n2){
            if(Left[i]<=Right[j]){
                nums[k]=Left[i];
                i++;
            }
            else{
                nums[k]=Right[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            nums[k]=Left[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=Right[j];
            j++;
            k++;
        }

    }




    void mergeSort(vector<int>& nums,int low,int high){
        
        if(low>=high){
            return ;
        }

        int mid = low+(high-low)/2;

        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);

        merger(nums,low,mid,high);

    }


    vector<int> sortArray(vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        int high=n-1;
        mergeSort(nums,low,high);
        return nums;

    }
};