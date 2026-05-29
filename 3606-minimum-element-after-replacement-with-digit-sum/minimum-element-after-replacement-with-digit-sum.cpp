class Solution {
public:
    int sumofD(int n){
        int d=0,r=0;
        while(n){
            d = n%10;
            r = r+d;
            n = n/10;
        }
        return r;
    }

    int minElement(vector<int>& nums) {
        int mini = INT_MAX;

        for(int num : nums){
            int sum = sumofD(num);
            mini = min(mini,sum);
        }

        return mini;
    }
};