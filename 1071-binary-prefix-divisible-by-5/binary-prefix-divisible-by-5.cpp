class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> answer(A.size());
        int remainder = 0;
        
        for(int i = 0; i < A.size(); i++) {
            remainder = (remainder << 1 | A[i])  % 5;
            answer[i] = !(bool)remainder;
        }
        return answer;
    }
};