class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        unordered_map<char, int> charCount;
        int maxOccurrence = 0;
        
        int left = 0, uniqueCount = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            charCount[s[right]]++;
            if (charCount[s[right]] == 1) uniqueCount++;  
            
            if (right - left + 1 > minSize) {
                if (--charCount[s[left]] == 0) uniqueCount--;  
                left++;
            }

            if (right - left + 1 == minSize && uniqueCount <= maxLetters) {
                string sub = s.substr(left, minSize);
                freq[sub]++;
                maxOccurrence = max(maxOccurrence, freq[sub]);
            }
        }
        
        return maxOccurrence;
    }
};