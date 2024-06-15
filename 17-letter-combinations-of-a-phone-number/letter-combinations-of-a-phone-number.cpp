class Solution {
public:
    vector<string> words={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void PhoneNum(string digits,vector<string>&ans,string newResults){
        
        if(digits.length()==0){
            ans.push_back(newResults);
            return;
        }

        char ch = digits[0];
        int idx = ch-'0';
        string wordbych = words[idx];
        string newDigits = digits.substr(1,(digits.size()));

        for(int i=0;i<wordbych.length();i++){
            char chh = wordbych[i];
            PhoneNum(newDigits,ans,newResults+chh);
        }
    }


    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits == ""){
            return ans;
        }
        PhoneNum(digits,ans,"");
        return ans;
        
    }


};