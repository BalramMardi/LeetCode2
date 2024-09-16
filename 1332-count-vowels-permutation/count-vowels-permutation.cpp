class Solution {
public:
    int countVowelPermutation(int n) {
        // Define the modulo
        const int MOD = 1000000007;
        
        // Initialize dp array for vowels 'a', 'e', 'i', 'o', 'u'
        long long aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        
        for (int i = 2; i <= n; ++i) {
            long long new_aCount = (eCount + iCount + uCount) % MOD;
            long long new_eCount = (aCount + iCount) % MOD;
            long long new_iCount = (eCount + oCount) % MOD;
            long long new_oCount = iCount % MOD;
            long long new_uCount = (iCount + oCount) % MOD;
            
            // Update the counts for the next iteration
            aCount = new_aCount;
            eCount = new_eCount;
            iCount = new_iCount;
            oCount = new_oCount;
            uCount = new_uCount;
        }
        
        // Sum all possible vowel permutations of length n
        long long result = (aCount + eCount + iCount + oCount + uCount) % MOD;
        
        return (int) result;
    }
};
