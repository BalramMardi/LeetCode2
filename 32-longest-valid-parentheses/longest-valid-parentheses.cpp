class Solution {
public:
    int longestValidParentheses(string s) {
        
        int close=0,open=0,maxa=0;

        for(char ch : s){
            if(ch == '('){
                open++;
            }
            else{
                close++;
            }


            if(open==close){
                maxa = max(maxa,2*close);
            }
            else if(close > open){
                close = 0;
                open=0;
            }
        }

        open=0,close=0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '('){
                open++;
            }
            else{
                close++;
            }


            if(close == open){
                maxa = max(maxa,2*open);
            }

            else if(close < open){
                open=0;
                close=0;
            }
        }

        return maxa;
    }
};