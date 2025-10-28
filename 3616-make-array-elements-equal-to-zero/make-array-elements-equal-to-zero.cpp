class Solution {
public:
    void solver(vector<int> nums, int curr, int dir, int &count)
{
    int n = nums.size();
    while (true)
    {
        if (curr < 0 || curr >= n)
        {
            
            if (all_of(nums.begin(), nums.end(), [](int x)
                       { return x == 0; }))
            {
                count++;
            }
            return;
        }
        if (nums[curr] == 0)
        {
            
            curr += dir;
        }
        else
        {
            
            nums[curr]--;
            dir = -dir;
            curr += dir;
        }
    }
}
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
    int count = 0;

    
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] == 0)
        {
            solver(nums, i, 1, count);  
            solver(nums, i, -1, count);
        }
    }

    return count;
    }
};