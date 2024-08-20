class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        
        for (auto it : nums) {
            if (it < 0) {
                neg.push_back(it);
            } else {
                pos.push_back(it);
            }
        }

      
        int posIndex = 0, negIndex = 0;
        bool flag = true;

        while (ans.size() < nums.size()) {
            if (flag && posIndex < pos.size()) {
                ans.push_back(pos[posIndex++]);
            } else if (!flag && negIndex < neg.size()) {
                ans.push_back(neg[negIndex++]);
            }
            flag = !flag; 
        }

        return ans;
    }
};




/* class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;

        for(auto it : nums){
            if(it<0){
                neg.push_back(it);
            }
            else{
                pos.push_back(it);

            }
        }
        bool flag = true;
        int i=0;
        while(ans.size() < nums.size()){
            if(flag){
                ans.push_back(pos[i]);
                flag=!flag;
            }
            else{
                ans.push_back(neg[i]);
                flag=!flag;
            }
            i++;
        }
        return ans;
    }
}; */