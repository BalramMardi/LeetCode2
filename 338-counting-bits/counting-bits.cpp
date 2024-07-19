class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counter(n+1,0);
        for(int i=1;i<=n;i++)
        { 
            counter[i]=counter[i & (i-1)]+1;
        }
        return counter;
};
};