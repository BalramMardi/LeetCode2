class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }


    int minimizeXor(int num1, int num2) {
        
        int curr = num1;
        int reqBits = __builtin_popcount(num2);
        int currBits = __builtin_popcount(num1);
        int bit=0;
        if(reqBits > currBits){
            while(reqBits > currBits){
                if(!isSet(curr,bit)){
                    setBit(curr,bit);
                    currBits++;
                }
                bit++;
            }
        }
        else if(reqBits < currBits){
            while(reqBits < currBits){
                if(isSet(curr,bit)){
                    unsetBit(curr,bit);
                    currBits--;
                }
                bit++;
            }
        }
        return curr;
    }
};