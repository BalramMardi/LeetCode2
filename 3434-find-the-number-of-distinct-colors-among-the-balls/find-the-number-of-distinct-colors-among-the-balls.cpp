class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> currColor;
        map<int, int> num;
        vector<int> ans;

        for(int i = 0; i < queries.size(); i++) {
            int index = queries[i][0], color = queries[i][1];

            if(currColor.find(index) != currColor.end()) {
                int prevColor = currColor[index];
                num[prevColor]--;
                if (num[prevColor] == 0) {
                    num.erase(prevColor);
                }
            }

            currColor[index] = color;
            num[color]++;

            ans.push_back(num.size());
        }

        return ans;
    }
};
