class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        
        for (const string& query : queries) {
            for (const string& word : dictionary) {
                int diffCount = 0;
                
                for (size_t i = 0; i < query.length(); ++i) {
                    if (query[i] != word[i]) {
                        diffCount++;
                    }
                }
                
                if (diffCount <= 2) {
                    result.push_back(query);
                    break; 
                }
            }
        }
        
        return result;
    }
};