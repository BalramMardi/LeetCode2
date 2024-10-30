class Solution {
public:
    unordered_map<string,unordered_map<string,double>>mp;
    void buildGraph(vector<vector<string>>& eq,vector<double>& values){
        for(int i=0;i<eq.size();i++){
            string A = eq[i][0];
            string B = eq[i][1];
            mp[A][B] = values[i];
            mp[B][A] = 1.0/values[i];
        }
    }
    double dfs(const string &start,const string &end,unordered_map<string,bool>&vis){
        if(mp.find(start)==mp.end() or mp.find(end)==mp.end()){
            return -1.0;
        }
        if(start==end){
            return 1.0;
        }

        vis[start]=true;

        for(auto &neigh : mp[start]){
            if(vis[neigh.first]==false){
                double result = dfs(neigh.first,end,vis);
                if(result != -1.0){
                    return result * neigh.second;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations,values);
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            string start = queries[i][0];
            string end = queries[i][1];
            unordered_map<string,bool> vis;
            double ans = dfs(start,end,vis);
            res.push_back(ans);
        }
        return res;
    }
};