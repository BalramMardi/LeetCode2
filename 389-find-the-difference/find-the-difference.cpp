class Solution {
public:
    char findTheDifference(string s, string t) {
         char ch = 0;
        // XOR all characters in both strings
        for (char c : s) {
            ch ^= c;
        }
        for (char c : t) {
            ch ^= c;
        }
        return ch;
    }
};