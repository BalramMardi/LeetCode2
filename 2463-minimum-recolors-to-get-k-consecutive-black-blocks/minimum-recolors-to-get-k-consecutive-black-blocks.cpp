class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int len = blocks.size();
        if (len < k) return -1;  

        int count = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] != 'B') {
                count++;
            }
        }

        int num = count; 

        for (int i = k; i < len; i++) {
            if (blocks[i - k] != 'B') count--;
            if (blocks[i] != 'B') count++;
            num = min(num, count);
        }

        return num;
    }
};
