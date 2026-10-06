class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;

        int close =0;

        for(char ch : s){
            if(ch == '('){
                close++;
            }
            else if(ch == ')'){
                if (close > 0) {
                    close--;
                } else {
                    open++;
                }
            }
        }

        return open+close;
    }
};