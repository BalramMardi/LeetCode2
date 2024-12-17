class NumArray {
public:
    vector<int> vec;
    NumArray(vector<int>& nums) {
        int pre=0;
        for(int i=0;i<nums.size();i++){
            pre = nums[i]+pre;
            vec.push_back(pre);
        }

    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return vec[right];
        }
        else{
            int ans = vec[right] - vec[left-1];
            return ans;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */