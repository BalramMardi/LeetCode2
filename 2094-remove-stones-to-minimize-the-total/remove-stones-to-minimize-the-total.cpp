class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k--){
            int first = pq.top();
            pq.pop();
            int newnum = first - floor(first/2);
            pq.push(newnum);
        }
        int count=0;
        while(pq.size()){
            count += pq.top();
            pq.pop();
        }

        return count;

    }
};