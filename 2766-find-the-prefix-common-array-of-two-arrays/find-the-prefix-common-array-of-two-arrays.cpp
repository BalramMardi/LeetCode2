class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size(),0);
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<A.size();i++){
            if(++mp[A[i]] == 2) count++;
            if(++mp[B[i]] == 2) count++;
            ans[i]=count;
        }

        return ans;
    }
};