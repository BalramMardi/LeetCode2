class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        unordered_map<int,int> mp;
        for(auto &it :  arr){
            mp[it]++;
        }

        for(auto &[num,freq]: mp){
            pq.push({freq,num});
        }

        while(k>0){
            auto temp = pq.top();
            int f=temp[0], num=temp[1];
            pq.pop();
            if(k>=f){
                k-=f;
            }
            else{
                k=0;
                pq.push({f-k,num});
            }
        }
        return pq.size();
    }
};