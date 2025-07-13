class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        int m=players.size();
        int n=trainers.size();

        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int i=0,j=0;

        int count=0;
        while(j < n && i < m){
            
            if(players[i] <= trainers[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;

            }


        }

        return count;
    }
};