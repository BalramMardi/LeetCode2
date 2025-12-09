class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n=arr.size();
        vector<bool> vis(n,0);

        queue<int> q;
        q.push(start);
        vis[start]=true;

        while(q.size()){

            int idx = q.front();
            q.pop();

            if(arr[idx] == 0){
                return true;
            }

            int idxplus = idx+arr[idx];
            int idxmin = idx-arr[idx];

            if(idxplus>=0 && idxplus<n && vis[idxplus]==false){
                vis[idxplus]=true;
                q.push(idxplus);
            }

            if(idxmin>=0 && idxmin<n && vis[idxmin]==false){
                vis[idxmin]=true;
                q.push(idxmin);
            } 
        }

        return false;
    }
};