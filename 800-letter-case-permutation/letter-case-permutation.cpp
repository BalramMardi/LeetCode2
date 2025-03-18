class Solution {
public:
    void solve(vector<string>& ans, int idx, string curr) {
        if (idx == curr.size()) {
            ans.push_back(curr);
            return;
        }

        solve(ans, idx + 1, curr); 

        if (!isdigit(curr[idx])) {
            curr[idx] = islower(curr[idx]) ? toupper(curr[idx]) : tolower(curr[idx]);
            solve(ans, idx + 1, curr); 
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(ans, 0, s);
        return ans;
    }
};
