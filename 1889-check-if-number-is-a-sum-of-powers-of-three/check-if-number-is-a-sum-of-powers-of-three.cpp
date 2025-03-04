class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        int rem;
        while(n!=0){
            rem = n % 3;
            n = n / 3;
            if(rem == 2){
                return false;
            }
        }

        return true;
    }
};