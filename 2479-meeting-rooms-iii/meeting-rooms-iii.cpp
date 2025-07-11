class Solution {
public:
    typedef pair<long long,int> pp;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pp,vector<pp>,greater<pp>> occupied; //time,rooms
        priority_queue<int,vector<int>,greater<int>> available; //rooms
        vector<int> count(n, 0);
        for(int i=0;i<n;i++){
            available.push(i);
        }
        int time=0;
        for(auto meeting : meetings){
            int start = meeting[0];
            int end = meeting[1];
            
            //release the occupied rooms
            while(occupied.size() and occupied.top().first <= start){
                available.push(occupied.top().second);
                occupied.pop();
            }

            
            if(available.size()){
                int room = available.top();
                occupied.push({end,room});
                available.pop();
                count[room]++;
            }
            //if there is no available rooms. we wait for it to get over
            else{
                auto [timedelay , room] = occupied.top();
                occupied.pop();
                occupied.push({timedelay+(end - start) , room});
                count[room]++;
            }

        }
        int max_meetings = 0, best_room = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > max_meetings) {
                max_meetings = count[i];
                best_room = i;
            }
        }
        return best_room;
    }
};