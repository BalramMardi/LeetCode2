class Solution {
public:

    bool isVowel(char ch){
        set<char> st = {'a', 'e', 'i', 'o','u'};
        return st.find(ch) != st.end();
    }

    bool isValidWord(string str) {
        return isVowel(str[0]) && isVowel(str.back());
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans;
        vector<int> vec(n,0);

        for(int i=0;i<n;i++){
            string s = words[i];
            if(i==0){
                if(isValidWord(s)){
                    vec[i] = vec[i]+1;
                }
            }
            else{
                if(isValidWord(s)){
                    vec[i] = vec[i-1]+1;
                }
                else{
                    vec[i] = vec[i-1];
                }
            }
        }

        for(int i = 0; i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(queries[i][0] == 0){
                ans.push_back(vec[right]);
            }
            else{
                ans.push_back(vec[right] - vec[left-1]);
            }
        }
        return ans;
    }
};