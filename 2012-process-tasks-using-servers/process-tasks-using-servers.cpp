#define pii pair<int,int>

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pii, vector<pii>, greater<pii>> avail;
        
    
        priority_queue<pair<long long, pii>, vector<pair<long long, pii>>, greater<pair<long long, pii>>> unavail;

        for(int i = 0; i < servers.size(); i++){
            avail.push({servers[i], i});
        }
        
        vector<int> ans(tasks.size());

        for(int i = 0; i < tasks.size(); i++){
            
            while(!unavail.empty() && unavail.top().first <= i){
                auto [x, server] = unavail.top();
                avail.push(server);
                unavail.pop();
            }

            if(!avail.empty()){
                auto [weight, idx] = avail.top();
                avail.pop();
                ans[i] = idx;
                
                unavail.push({(long long)i + tasks[i], {weight, idx}});
            }
            else{
                auto [time, server] = unavail.top();
                unavail.pop();
                time += tasks[i]; 
                ans[i] = server.second;
                unavail.push({time, server});
            }
        }

        return ans;
    }
};