class Solution {
public:
    typedef pair<double,pair<int,int>> pii;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();

        priority_queue<pii,vector<pii>,greater<>> pq;
        for(int i=1;i<n;i++){
            pq.push({(double)arr[0] / arr[i],{0,i}});
        }

        while(--k){
            auto [val, ij] = pq.top(); 
            auto [i, j] = ij;         
            pq.pop();

            if(i+1 < j){
                pq.push({(double)arr[i+1] / arr[j],{i+1,j}});
            }
        }

        vector<int> ans;

        ans.push_back(arr[pq.top().second.first]);
        ans.push_back(arr[pq.top().second.second]);


        return ans;
    }
};

/* class Solution {
public:
    typedef pair<double,pair<int,int>> pii;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();

        priority_queue<pii,vector<pii>,greater<>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({(double)arr[i] / arr[j],{arr[i],arr[j]}});
            }
        }

        while(--k){
            pq.pop();
        }

        vector<int> ans;

        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);


        return ans;
    }
}; */