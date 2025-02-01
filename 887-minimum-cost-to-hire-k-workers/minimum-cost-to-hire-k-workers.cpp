class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        vector<pair<double,int>> vec;

        for(int i=0;i<n;i++){
            vec.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(vec.begin(),vec.end());

        priority_queue<int> pq;

  
        double mini = DBL_MAX;
        double currQuality=0;
        for(int i=0;i<n;i++){
            pq.push(vec[i].second);
            currQuality += vec[i].second;
            
            if(pq.size() > k){
                currQuality -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
               
                mini = min(mini , currQuality * vec[i].first);
            }

        }

        return mini;
    }
};