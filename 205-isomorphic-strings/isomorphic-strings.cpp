class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s1(200,0);
        vector<int> t1(200,0);

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0;i<s.length();i++){
            if(s1[s[i]]!=t1[t[i]]){
                return false;
            }

            s1[s[i]]=i+1;
            t1[t[i]]=i+1;

        }

        return true;

    }
};