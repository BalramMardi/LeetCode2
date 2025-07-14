class Solution {
public:

    int dp[11][2][11][11][20][2];

    int solve(string str,int idx, bool tight, int even, int odd,int rem,bool validNum ,int k){

        if(idx == str.size()){

            return (((even)==(odd))&&(rem==0));
        }

        if(dp[idx][tight][even][odd][rem][validNum]!=-1){
            return dp[idx][tight][even][odd][rem][validNum];
        }


        int limit= (tight)?str[idx]-'0':9;


        int res=0;
        for(int i=0;i<=limit;i++){
            bool newTight = (tight) && (i==limit);
            
            if(validNum==false && i==0){
                res += solve(str,idx+1,newTight,even,odd,rem,false,k);
            }
            else
                 res += (solve(str,idx+1,newTight,even + (i%2==0),odd + (i%2!=0),(rem*10+i)%k,true,k));
        }

        return dp[idx][tight][even][odd][rem][validNum]=res;

    }



    int countBeautiful(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s, 0, true, 0, 0, 0, false, k);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        return countBeautiful(to_string(high), k) - countBeautiful(to_string(low - 1), k);
    }

};