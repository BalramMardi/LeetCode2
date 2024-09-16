class Solution {
public:
    int M = 1e9+7;
    int numberOfWays(string corridor) {
        vector<int> seat;
        for(int i=0;i<corridor.length();i++){
            if(corridor[i]=='S'){
                seat.push_back(i);
            }
        }

        if(seat.size() %2 !=0 || seat.size()==0){
            return 0;
        }
        long long count=1;
        int first=seat[1];
        for(int i=2;i<seat.size();i+=2){
            int diff = seat[i]-first;
            count =( count * diff )% M;
            first = seat[i+1];
        }

        return count % M;
    }
};