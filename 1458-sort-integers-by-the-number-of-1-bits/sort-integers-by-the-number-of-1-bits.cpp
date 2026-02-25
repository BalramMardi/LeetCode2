class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> vec;
        for(int it:arr){
            int k=__builtin_popcount(it);
            vec.push_back({k,it});
        }

        sort(vec.begin(),vec.end());

        vector<int> ans;
        for(auto it:vec){
            ans.push_back(it.second);
        }

        return ans;
    }
};