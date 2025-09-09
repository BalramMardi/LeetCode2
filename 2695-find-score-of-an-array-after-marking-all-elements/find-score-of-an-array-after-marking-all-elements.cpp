class Solution {
public:
    typedef pair<int,int> pii;
    long long findScore(vector<int>& nums) {
        
        int n= nums.size();
        vector<bool> flag(n,false);

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        long long sum=0;
        while(pq.size()){

            int val = pq.top().first;
            int idx = pq.top().second;

            pq.pop();

            if(flag[idx] == false){

                sum += val;
                flag[idx] = true;  
                if (idx - 1 >= 0) flag[idx - 1] = true;
                if (idx + 1 < n) flag[idx + 1] = true;
            }

        }


        return sum;



    }
};