class Solution {
public:

    string findWord(string word){
        int arr[26]={0};

        for(auto &ch:word){
            arr[ch-'a']++;
        }

        string results="";
        for(int i=0;i<26;i++){
            int freq = arr[i];
            if(freq>0)
                results += string(freq,i+'a');
        }
        return results;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
            string word = strs[i];
            string newWord = findWord(word);
            mp[newWord].push_back(word);
        }
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
