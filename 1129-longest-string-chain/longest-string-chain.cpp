class Solution {
public:
    bool isPossible(string s1, string s2){
        if(s1.length() != s2.length() + 1) return false;
        int i = 0, j = 0;
        while(i < s1.length()){
            if(j < s2.length() && s1[i] == s2[j]){
                j++;
            }
            i++;
        }
        return j == s2.length();
    }

    int longestStrChain(vector<string>& words) {
        vector<pair<int,string>> vec;
        vector<int> dp(words.size(), 1); 

        for(auto it: words){
            vec.push_back({it.length(),it});
        }

        sort(vec.begin(), vec.end());

        int omax = 1;
        for(int i = 1; i < vec.size(); i++){
            for(int j = 0; j < i; j++){
                if(vec[j].first + 1 == vec[i].first){
                    if(isPossible(vec[i].second, vec[j].second)){
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            omax = max(dp[i], omax);
        }
        
        return omax;
    }
};
