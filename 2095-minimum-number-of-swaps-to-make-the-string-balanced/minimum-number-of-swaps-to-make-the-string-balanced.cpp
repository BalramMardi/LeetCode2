class Solution {
public:
    int minSwaps(string s) {
        int maxx=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                count++;
            }
            else{
                count--;
            }
            maxx=max(maxx,count);
        }

        return (maxx+1)/2 ;
        
    }
};