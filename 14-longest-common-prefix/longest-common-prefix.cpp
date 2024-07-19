class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];

        int idx=0;
        while(idx<s1.length() and idx<s2.length()){
            if(s1[idx] == s2[idx]){
                idx++;
            }
            else{
                break;
            }
        }

        return s1.substr(0,idx);


        
    }
};