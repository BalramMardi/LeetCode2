class Solution {
public:
    int countVowelStrings(int n) {
        long long res = 1;
        
        for (int i = 1; i <= 4; ++i) {
            res = res * (n + 5 - i) / i;
        }
        return (int)res;
    }
};