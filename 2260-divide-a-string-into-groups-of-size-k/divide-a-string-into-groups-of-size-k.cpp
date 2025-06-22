class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    

        int n=s.size();
        int curr=0;

        vector<string> ans;
        while(curr < n){
            ans.push_back(s.substr(curr,k));
            curr += k;
        }

        ans.back() += string(k - ans.back().length(), fill);
        return ans;

    }
};