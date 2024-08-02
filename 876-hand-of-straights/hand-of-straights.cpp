class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        if(hand.size() % gs !=0){
            return false;
        }
        map<int,int> mp;
        for(int it : hand){
            mp[it]++;
        }

        while(mp.size()){
            int curr = mp.begin()->first;
            for(int i=0;i<gs;i++){
                if(mp[curr+i]==0){
                    return false;
                }
                mp[curr+i]--;

                if(mp[curr+i]<1){
                    mp.erase(curr+i);
                }
            }
        }

        return true;
    }
};