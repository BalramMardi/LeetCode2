class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int curr = 0;
        if(len1 % 2 == 0 and len2 % 2 == 0){
            return 0;
        }
        else if( len1 % 2 !=0 and len2 % 2==0){
            
            for(int i=0;i<len2;i++){
                curr = curr ^ nums2[i];
            }
        }
        else if( len1 % 2 == 0 and len2 % 2 !=0){
            for(int i=0;i<len1;i++){
                curr = curr ^ nums1[i];
            }
        }
        else if(len1 % 2 != 0 and len2 % 2 != 0 ){
            for(int i=0;i<len1;i++){
                curr = curr ^ nums1[i];
            }
            for(int i=0;i<len2;i++){
                curr = curr ^ nums2[i];
            }
        }

        return curr;
    }
};