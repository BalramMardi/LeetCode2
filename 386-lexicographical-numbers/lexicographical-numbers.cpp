class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> str;
        vector<int> ans;

        for(int i=1;i<=n;i++){
            string word = to_string(i);

            str.push_back(word);
        }

        sort(str.begin(),str.end());

        for(int i=0;i<str.size();i++){
            int num = stoi(str[i]);
            ans.push_back(num);
        }

        return ans;
    }
};