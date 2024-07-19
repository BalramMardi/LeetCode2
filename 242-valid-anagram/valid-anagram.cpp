class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
  
        for(auto &it: s){
            mp1[it]++;
        }
        for(auto &vt : t){
            mp1[vt]--;
        }

        
        for(auto &[key,freq] : mp1){
            if(freq != 0){
                return false;
            }
        }
        return true;

    }
};