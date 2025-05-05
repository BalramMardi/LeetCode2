class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>> mp;
        char ch = 'a';
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                mp[ch] = {i, j};
                ch++;
            }
        }
        mp['z'] = {5, 0};

        string ans = "";
        int startX = 0, startY = 0;

        for (char ch : target) {
            int endX = mp[ch].first;
            int endY = mp[ch].second;

            int diffX = endX - startX;
            int diffY = endY - startY;
            
            if (diffX < 0) ans += string(-diffX, 'U');
            if (diffY < 0) ans += string(-diffY, 'L');
            if (diffX > 0) ans += string(diffX, 'D');
            if (diffY > 0) ans += string(diffY, 'R');

            ans += '!';
            startX = endX;
            startY = endY;
        }

        return ans;
    }
};





/* class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char,pair<int,int>> mp;

        char ch = 'a';
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                mp[ch]={i,j};
                ch = ch+1;
            }
        }
        mp['z']={5,0};

        string ans = "";

        int startX = 0,startY=0;
        for(int i=0;i<target.size();i++){
            char ch = target[i];
            int endX = mp[ch].first;
            int endY = mp[ch].second;

            int diffX = startX - endX;
            int diffY = startY-endY;

            if(ch!='z'){
                if(diffX > 0 ){
                ans += string(diffX , 'U');
                }
                else if(diffX < 0){
                    ans += string(abs(diffX) , 'D');
                }

                if(diffY > 0 ){
                    ans += string(diffY , 'L');
                }
                else if(diffY < 0){
                    ans += string(abs(diffY) , 'R');
                }

                ans += "!";

                startX = endX;
                startY = endY;
            }
            else{
                if(diffY > 0 ){
                    ans += string(diffY , 'L');
                }
                else if(diffY < 0){
                    ans += string(abs(diffY) , 'R');
                }

                if(diffX > 0 ){
                ans += string(diffX , 'U');
                }
                else if(diffX < 0){
                    ans += string(abs(diffX) , 'D');
                }

                ans += "!";

                startX = endX;
                startY = endY;
            }

            
            
        }

        return ans;
    }
}; */