#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            if (lastIndex[currentChar] >= left) {
                left = lastIndex[currentChar] + 1;
            }
            lastIndex[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};


/* class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        
        return maxLength;
    }
}; */