class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {


        if(stones.size()==1){
            return stones[0];
        }
        priority_queue<int> pq;

        for(auto it:stones){
            pq.push(it);
        }

        while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            int diff=y-x;
            if(y-x !=0){
                pq.push(diff);
            }
        }

        if(pq.size()==0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};