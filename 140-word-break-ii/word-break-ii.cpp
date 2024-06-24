#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    unordered_set<string> wordSet;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return solve(s, 0);
    }

    vector<string> solve(const string& s, int start) {
        vector<string> result;
        if (start == s.size()) {
            result.push_back("");
            return result;
        }

        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (wordSet.find(word) != wordSet.end()) {
                vector<string> subList = solve(s, end);
                for (string sub : subList) {
                    result.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }

        return result;
    }
};
