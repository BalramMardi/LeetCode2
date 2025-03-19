class Solution {
public:

    void solve(int k, int n, int idx, vector<int>& path, vector<vector<int>>& ans) {
        if (n < 0) return; 
        if (k == 0) {
            if (n == 0) ans.push_back(path); 
            return;
        }

        for (int i = idx; i <= 9; i++) {  
            path.push_back(i); 
            solve(k-1, n-i, i+1, path, ans); 
            path.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(k,n,1,path,ans);
        return ans;
    }
};