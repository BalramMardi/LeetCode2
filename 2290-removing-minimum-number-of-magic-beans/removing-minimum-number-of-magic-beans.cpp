class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long total = accumulate(beans.begin(),beans.end(),0L);
        long long mini = LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            long long curr = total -(beans[i]*(long long)(n-i));
            mini = min(curr, mini);
        }

        return mini;

    }
};