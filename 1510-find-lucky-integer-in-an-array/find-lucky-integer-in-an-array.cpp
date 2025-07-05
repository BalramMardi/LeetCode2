class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int num : arr){
            mp[num]++;
        }

        int count=-1;

        for(int n : arr){
            if(n == mp[n]){
                count= max(count,n);
            }
        }

        return count;
    }

};