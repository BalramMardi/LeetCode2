class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> pairs;
        int n=spells.size();
        int m=potions.size();
        for(int i=0;i<n;i++){
            
            int low=0,high=m-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if((long long)spells[i]*(long long)potions[mid] < success){
                    low = mid+1;
                } 
                else{
                    high = mid-1;
                }
            }
            pairs.push_back(m-low);
        }

        return pairs;
    }
};