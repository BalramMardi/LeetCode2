class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pii,vector<pii>,greater<>> pq;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[0].size();j++){
                sum += mat[i][j];
            }
            pq.push({sum,i});
        }

        vector<int> ans;

        while(k--){
            auto [_,i] = pq.top();
            pq.pop();

            ans.push_back(i);
        }

        return ans;
    }
};