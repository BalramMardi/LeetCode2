class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
    vector<int> vec(n + 1, 0); 
    for (auto &it : queries)
    {
        int left = it[0];
        int right = it[1];
        vec[left]--; 
        if (right + 1 < n)  vec[right + 1]++;
        
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        count += vec[i];
        nums[i] += count; 
        if (nums[i] > 0)  return false;
    }
    return true;
    }
};