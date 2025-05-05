class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        
        unordered_map<int,int> mp;

        long long count=0;

        for(int i=0;i<hours.size();i++){

            int rem = hours[i] % 24;

            int complement = (24-rem)% 24;

            count += mp[complement];

            mp[rem]++;
        }

        return count;
    }
};