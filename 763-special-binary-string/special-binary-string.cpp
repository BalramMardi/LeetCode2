class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> goodString;
        int start=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }
            else{
                count--;
            }

            if(count==0){
                goodString.push_back("1"+makeLargestSpecial(s.substr(start+1,i-start-1))+"0");
                start = i+1;
            }

        }

        sort(goodString.rbegin(),goodString.rend());

        string result;
        for (const string &sub : goodString) {
            result += sub;
        }

        return result;
    }
};