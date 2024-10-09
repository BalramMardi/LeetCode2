class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size(),carry=0;
        vector<int> res;
        for (int i=n-1;i>=0 || k>0 || carry>0;i--) {
            int digit = (i >= 0) ? num[i] : 0;
            digit += k % 10 + carry;
            k /= 10;
            carry = digit / 10;
            res.push_back(digit % 10);
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};