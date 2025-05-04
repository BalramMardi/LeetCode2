class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        
      
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

    
        for(auto& op : operations) {
            int old_val = op[0];
            int new_val = op[1];
            
            int idx = mp[old_val];
            nums[idx] = new_val;
            
            mp.erase(old_val);           
            mp[new_val] = idx;
        }

        return nums;
    }
};
