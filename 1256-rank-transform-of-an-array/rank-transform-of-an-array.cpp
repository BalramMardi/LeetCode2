class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> vec(arr.begin(),arr.end());

        sort(vec.begin(),vec.end());

        vec.erase(unique(vec.begin(),vec.end()),vec.end());

        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            ans[i] = lower_bound(vec.begin(),vec.end(),arr[i])-vec.begin()+1;
        }

        return ans;

    }
};