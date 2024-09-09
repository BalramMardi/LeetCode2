class Solution {
public:

    bool isPalindrome(string s, int idx,int i){
        while(idx < i){
            if(s[idx]!=s[i]){
                return false;
            }
            idx++;
            i--;
        }
        return true;
    }

    void backtrack(string s,int idx, vector<string>&path,vector<vector<string>>&ans){

        if(idx == s.length()){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,path,ans);
                path.pop_back();
            }

            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>> ans;
        backtrack(s,0,path,ans);
        return ans;
    }
};