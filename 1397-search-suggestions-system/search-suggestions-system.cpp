class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string searchWord) {
        auto it = p.begin();
        sort(p.begin(),p.end());
        vector<vector<string>> res;
        string curr = "";
        for(char c : searchWord){
            curr +=c;
            vector<string> level;
            it = lower_bound(it,p.end(),curr);
            for(int i=0;i<3 && it+i != p.end();i++){
                string &s = *(it+i);
                if(s.find(curr)) break;
                level.push_back(s);
            }
            res.push_back(level);
        }
        return res;
    }
};