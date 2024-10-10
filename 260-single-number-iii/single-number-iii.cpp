class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long res=0;
        for(auto it:nums){
            res =res^ it;
        }
        long long diff = res & -res;

        int num1=0,num2=0;
        for(auto it:nums){
            if(it & diff){
                num1 ^= it;
            }
            else{
                num2 ^= it;
            }
        }
        return {num1, num2};
    }
};