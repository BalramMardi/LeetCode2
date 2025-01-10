class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for(int i = 0; i < 26; i++) {
            if(temp[i] < freq2[i]) {
                return false; 
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        vector<int> freq2(26);
     
        for(string &word : words2) { 
            int temp[26] = {0};

            for(char &ch : word) {
                temp[ch-'a']++;

                freq2[ch-'a'] = max(freq2[ch-'a'], temp[ch-'a']);
            }
        }
  
        for(string &word : words1) {
            vector<int> temp(26, 0);

            for(char &ch : word) { 
                temp[ch-'a']++;
            }

            if(isSubset(freq2, temp) == true) { 
                result.push_back(word);
            }
        }

        return result;
    }
};


/* class Solution {
public:


    vector<int> count(const string& S) {
        vector<int> ans(26, 0);
        for (char c : S) {
            ans[c - 'a']++;
        }
        return ans;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> bmax(26, 0);
        
        for (const string& b : B) {
            vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i) {
                bmax[i] = max(bmax[i], bCount[i]);
            }
        }

        vector<string> ans;
        for (const string& a : A) {
            vector<int> aCount = count(a);
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(a);
            }
        }

        return ans;
    }
}; */