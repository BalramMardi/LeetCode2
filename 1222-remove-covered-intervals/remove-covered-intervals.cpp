class Solution {
public:

static bool comparator(const vector<int>&a,vector<int>&b){
    if(a[0] == b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
}


    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comparator);

        int prevEnd=0,count=0;
        for(auto interval:intervals){
            if(interval[1] > prevEnd){
                count++;
                prevEnd = interval[1];
            }

        }
        return count;
    }
};