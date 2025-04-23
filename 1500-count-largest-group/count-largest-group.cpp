class Solution {
public:

    int solve(int n){
        int sum=0;
        while(n){
            int d = n%10;
            sum +=d;
            n/=10;
        }

        return sum;
    }


    int countLargestGroup(int n) {
        unordered_map<int,int> mp;

        for(int i=1;i<=n;i++){
            int num = solve(i);
            mp[num]++;
        }

        int maxSize = 0;
        for(auto& [key, val] : mp){
            maxSize = max(maxSize, val);
        }

        int count = 0;
        for(auto& [key, val] : mp){
            if(val == maxSize) count++;
        }

        return count;
    }
};