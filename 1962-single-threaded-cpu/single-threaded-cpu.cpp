class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        vector<array<int, 3>> sortedTasks;
        
        for(int i = 0; i<n; i++) {       
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(begin(sortedTasks), end(sortedTasks)); //O(nlogn)
        
        vector<int> result;
        
        long long curr_time = 0;
        int idx = 0;
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq; //min_heap
        
        while(idx < n || !pq.empty()) {
            
            if(pq.empty() && curr_time < sortedTasks[idx][0]) {
                curr_time = sortedTasks[idx][0];
            }
            
            
            while(idx < n && sortedTasks[idx][0] <= curr_time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]}); //log(n)
                idx++;
            }            
            
            curr_time += pq.top().first; //processing time
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};