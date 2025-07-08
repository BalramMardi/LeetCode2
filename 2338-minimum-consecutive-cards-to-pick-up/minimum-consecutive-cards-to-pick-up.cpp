class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        int n=cards.size();
        unordered_set<int> st;

        int left=0;
        int maxi = INT_MAX;
        for(int right=0;right<n;right++){

            while(st.count(cards[right])){
                maxi = min(right-left+1,maxi);
                st.erase(cards[left]);
                left++;
            }

            st.insert(cards[right]);


        }

        return ((maxi==INT_MAX) ? -1 : maxi) ;
    }
};