class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> v;
         
        for(int i = 0 ; i < dist.size() ; i++)
            v.push_back((float) dist[i] / speed[i]);
            
        sort(v.begin(), v.end());
        int count = 0;
        int time = 0, i = 0;
        /* while(i < v.size()) {
            if(time >= v[i])
                return count;
            ++count;
            time += 1;
            ++i;
        } */
        count =1,time=1;
        for(int i=1;i<v.size();i++){
            if(v[i]-time<=0){
                return count;
            }
            count++;
            time += 1;
        }
        return count;
    }
};