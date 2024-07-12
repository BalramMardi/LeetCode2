class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        list<int> lq;
        int left=0,right=nums.size()-1;
        vector<int> ans;
        while(left<=right){
            if((nums[left]*nums[left]) > (nums[right]*nums[right])){
                lq.push_front(nums[left]*nums[left]);
                left++;
            }
            else{
                lq.push_front(nums[right]*nums[right]);
                right--;
            }
        }

        while(lq.size()){
            ans.push_back(lq.front());
            lq.pop_front();
        }
        return ans;
    }
};