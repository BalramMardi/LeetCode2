class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerFirst(26, -1); 
        vector<int> lowerLast(26, -1);  
        vector<int> upperFirst(26, -1);
        
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (islower(c)) {
                int idx = c - 'a';
                if (lowerFirst[idx] == -1) {
                    lowerFirst[idx] = i;
                }
                lowerLast[idx] = i;
            } else {
                int idx = c - 'A';
                if (upperFirst[idx] == -1) {
                    upperFirst[idx] = i;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (lowerFirst[i] != -1 && upperFirst[i] != -1 && lowerLast[i] < upperFirst[i]) {
                count++;
            }
        }
        return count;
    }
};