class Solution {
public:
    int totalFruit(vector<int>& A) {
         int i=0,j=0,n=A.size(),maxi=0;

        unordered_map<int,int>m;
        while(j<n)
        {
            m[A[j]]++;
            if(m.size()>2){
                if(--m[A[i]]==0)m.erase(A[i]);
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
       
        return maxi;
    }
};