class Solution {
public:

   static bool comparator(pair<char,int>&a,pair<char,int> &b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char,int> mp;
        string st="";

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());
        sort(freqVec.begin(),freqVec.end(),comparator);

        for(auto &[key,freq]: freqVec){
            while(freq--){
                st += key;
            }
        }

        return st;
    }
};