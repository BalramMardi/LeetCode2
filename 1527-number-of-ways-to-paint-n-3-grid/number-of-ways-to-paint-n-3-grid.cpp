class Solution {
public:
    int numOfWays(int n) {
        long long typeA = 6;
        long long typeB = 6;
        long long mod = 1e9 + 7;
        
        for (int i = 2; i <= n; i++) {
            long long nextA = (2 * typeA + 2 * typeB) % mod;
            long long nextB = (2 * typeA + 3 * typeB) % mod;
            typeA = nextA;
            typeB = nextB;
        }
        
        return (typeA + typeB) % mod;
    }
};