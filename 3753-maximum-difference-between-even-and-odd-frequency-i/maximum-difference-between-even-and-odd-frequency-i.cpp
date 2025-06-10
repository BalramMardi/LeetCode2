class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);

        for(auto ch : s){
            freq[ch-'a']++;
        }

        int oddMax=1;
        int evenMin=s.size();
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue; 


            if(freq[i] & 1){
                oddMax = max(oddMax,freq[i]);
            }
            else{
                evenMin = min(evenMin,freq[i]);
            }
        }

        return oddMax - evenMin;
    }
};