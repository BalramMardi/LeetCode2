class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i-1]=='A' && colors[i+1]=='A' && colors[i]=='A'){
                a++;
            }
            else if(colors[i-1]=='B' && colors[i+1]=='B' && colors[i]=='B'){
                b++;
            }
        }
        if(a>b){
            return true;
        }

        return false;
    }
};