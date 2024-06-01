class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxx=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);  
        }
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]-1) == st.end()){
                int j=nums[i];
                while(st.find(j)!= st.end()){
                    j++;
                }
                maxx=max(maxx,j-nums[i]);
            }
        }
        return maxx;

    }
};