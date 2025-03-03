class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> equal;
        vector<int> larger;
        vector<int> ans;


        for(auto num : nums){
            if(num > pivot){
                larger.push_back(num);
            }
            else if(num < pivot){
                smaller.push_back(num);
            }
            else if(num == pivot){
                equal.push_back(num);
            }
        }

        for(int i=0;i<smaller.size();i++){
            ans.push_back(smaller[i]);
        }
        for(int i=0;i<equal.size();i++){
            ans.push_back(equal[i]);
        }
        for(int i=0;i<larger.size();i++){
            ans.push_back(larger[i]);
        }

        return ans;
    }
};