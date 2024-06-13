#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size=nums1.size();
        vector<pair<int,int>> pairs(size);

        for(int i=0;i<nums1.size();i++){
            pairs.push_back({nums1[i],nums2[i]});
        }
        //sort wrt the second array
        sort(pairs.begin(),pairs.end(),[](pair<int,int>a,pair<int,int>b){
            return (a.second > b.second);
        });

        priority_queue<int,vector<int>,greater<int>> minh;
        long long curr=0;
        long long maxSum = INT_MIN;

        for(int i=0;i<size;i++){
            curr += pairs[i].first;
            minh.push(pairs[i].first);

            if(minh.size()>k){
                curr -= minh.top();
                minh.pop();
            }
            if(minh.size()==k){
                maxSum = max(maxSum ,(curr * pairs[i].second));
            }
        }
        return maxSum;





    }
};