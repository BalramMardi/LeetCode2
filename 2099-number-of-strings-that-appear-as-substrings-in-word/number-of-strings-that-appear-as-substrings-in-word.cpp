class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(string &it : patterns){
            if(word.find(it)!=string::npos){
                cnt++;
            }
        }
        return cnt;
    }
};