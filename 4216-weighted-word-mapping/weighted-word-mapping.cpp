class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto word: words){
            int sum=0;
            for(char ch :  word){
                int code = ch-'a';
                sum+=weights[code];
            }
            sum = sum%26;
            char ch = 'z' - (sum);
            ans += ch;
        }

        return ans;
    }
};