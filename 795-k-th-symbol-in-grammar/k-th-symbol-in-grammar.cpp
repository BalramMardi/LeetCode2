class Solution {
public:
    int kthGrammar(int n, int k) {
        int curr = 0;
        int left = 1;
        int right = (int)pow(2, n-1);
        for(int i = 1; i<=n; i++){
            int mid = (left + right)/2;
            if(k <= mid)
                right = mid;
            else{
                left = mid + 1;
                if(curr == 1)
                    curr = 0;
                else
                    curr = 1;
            }   
        }
        return curr;
    }
};