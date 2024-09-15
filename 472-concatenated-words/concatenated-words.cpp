class Solution {
public:
    unordered_map<string,bool>mp;
    bool isPossible(string word,unordered_set<string>&st){
        if(mp.find(word) != mp.end())
            return mp[word];
        int l=word.length();
        for(int i=0;i<l;i++){
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);

            if(st.find(prefix)!=st.end() && isPossible(suffix,st) || st.find(prefix)!=st.end() && st.find(suffix)!=st.end()){
                return  mp[word]= true;
            }
        }

        return  mp[word]= false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words),end(words));
        vector<string> ans;
        mp.clear();
        for(auto it : words){
            if(isPossible(it,st))
                ans.push_back(it);
            

        }

        return ans;
    }
};