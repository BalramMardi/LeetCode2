class Solution {
public:
typedef pair<int,int> pp;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pp,vector<pp>,greater<pp>> occupied;
        priority_queue<int,vector<int>,greater<int>> available;

        for(int i=0;i<times.size();i++){
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());

        for(int i=0;i<times.size();i++){
            available.push(i);
        }

        for(int i=0;i<times.size();i++){
            int arrival = times[i][0];
            int leave = times[i][1];
            int index = times[i][2];

            while(occupied.size() and occupied.top().first <= arrival){
                available.push(occupied.top().second);
                occupied.pop();
            }

            int currSeat = available.top();
            available.pop();
            occupied.push({leave,currSeat});

            if(index == targetFriend){
                return currSeat;
            }

        }

        return -1;
    }
};