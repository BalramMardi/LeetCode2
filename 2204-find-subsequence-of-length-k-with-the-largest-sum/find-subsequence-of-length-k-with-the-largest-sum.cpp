class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        vector<pair<int,int>> curr;
        while(k--){
            curr.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }

        sort(curr.begin(),curr.end());

        vector<int> ans;
        for(auto it : curr){
            ans.push_back(it.second);
        }

        return ans;
    }
};