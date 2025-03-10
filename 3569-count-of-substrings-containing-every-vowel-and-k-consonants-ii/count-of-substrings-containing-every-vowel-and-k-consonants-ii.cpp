class Solution {
public:
    long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }

private:
    long atLeastK(string word, int k) {
        long numValidSubstrings = 0;
        int start = 0;
        int end = 0;

        unordered_map<char, int> vowelCount;
        int consonantCount = 0;

        while (end < word.length()) {
            char newLetter = word[end];

            if (isVowel(newLetter)) {
                vowelCount[newLetter]++;
            } else {
                consonantCount++;
            }

            while (vowelCount.size() == 5 and consonantCount >= k) {
                numValidSubstrings += word.length() - end;
                char startLetter = word[start];
                if (isVowel(startLetter)) {
                    if (--vowelCount[startLetter] == 0) {
                        vowelCount.erase(startLetter);
                    }
                } else {
                    consonantCount--;
                }
                start++;
            }

            end++;
        }

        return numValidSubstrings;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


/* class Solution {
public:
    typedef long long ll;
    long long countOfSubstrings(string word, int k) {
        ll len = k+5;

        set<char> vowels = {'a','e','i','o','u'};
        unordered_map<char,int> mp = {{'a',0},{'e',0},{'i',0},{'o',0},{'u',0}};
        

        int count=0;
        int vowelCount=0;
        int constCount=0;

        for(int i=0;i<len;i++){
            char ch=word[i];
            if(vowels.find(ch)!=vowels.end()){
                mp[ch]++;
                vowelCount++;
            }
            else{
                constCount++;
            }
        } 

        bool flag = true;
        if(vowelCount+constCount == len){
            for(auto &[ch,freq] : mp){
                if(freq != 1){
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            count++;
        }

        for(int i=len;i<word.size();i++){
            char ch = word[i-len];
            if(vowels.find(ch) != vowels.end()){
                mp[ch]--;
                vowelCount--;
            }
            else{
                constCount--;
            }
            char newch = word[i];
            if(vowels.find(newch) != vowels.end()){
                mp[newch]++;
                vowelCount++;
            }
            else{
                constCount++;
            }
            bool flag = true;
            if(vowelCount+constCount == len){
                for(auto &[ch,freq] : mp){
                    if(freq != 1){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                count++;
            }
            
        }

        return count;


    }
}; */