class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        map<int,int> flower;

        for(int i=0;i<n;i++){
            flower[flowers[i][0]]++;
            flower[flowers[i][1]+ 1]--;
        }

        vector<pair<int,int>> budding;

        int count=0;
        for(auto &[index , freq] : flower){
            count += freq;
            budding.push_back({index,count});
        }
        vector<int> ans;
        for(int it : people){

            auto lower = lower_bound(budding.begin(),budding.end(),make_pair(it,INT_MAX));
            if(lower == budding.begin()){
                ans.push_back(0);
            }
            else{
                lower--;
                ans.push_back(lower->second);
            }
        }

        return ans;

    }
};