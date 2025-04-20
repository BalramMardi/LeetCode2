class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int cal=0;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }

        for(auto it: mp){
            int key=it.first;
            int freq=it.second;
            int gp=ceil((double)freq/(key+1));
            cal+=gp*(key+1);
        }

        return cal;
    }
};