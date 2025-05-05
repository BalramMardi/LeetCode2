class Solution {
public:
    string devowel(string s) {
        for (char &c : s) {
            if (isVowel(c)) c = '*';
            else c = tolower(c);
        }
        return s;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowercaseMap;
        unordered_map<string, string> devowelMap;

        for (string word : wordlist) {
            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            string devow = devowel(word);
            if (lowercaseMap.find(lower) == lowercaseMap.end())
                lowercaseMap[lower] = word;
            if (devowelMap.find(devow) == devowelMap.end())
                devowelMap[devow] = word;
        }

        vector<string> result;
        for (string q : queries) {
            if (exactWords.count(q)) {
                result.push_back(q);
                continue;
            }
            string lowerQ = q;
            transform(lowerQ.begin(), lowerQ.end(), lowerQ.begin(), ::tolower);
            if (lowercaseMap.count(lowerQ)) {
                result.push_back(lowercaseMap[lowerQ]);
                continue;
            }
            string devowQ = devowel(q);
            if (devowelMap.count(devowQ)) {
                result.push_back(devowelMap[devowQ]);
                continue;
            }
            result.push_back("");
        }

        return result;
    }
};
