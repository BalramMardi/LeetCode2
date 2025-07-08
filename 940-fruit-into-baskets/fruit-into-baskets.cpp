class Solution {
public:
    int totalFruit(vector<int>& A) {
         int left=0,right=0,n=A.size(),maxi=0;

        unordered_map<int,int>m;

        for(int right=0;right<n;right++)
        {
            m[A[right]]++;

            if(m.size()>2){
                if(--m[A[left]]==0)m.erase(A[left]);
                left++;
            }
            
            maxi=max(maxi,right-left+1);
        }
       
        return maxi;
    }
};