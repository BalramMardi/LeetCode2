class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        stack<char> st;
        st.push(']');

        int n=s.size();

        for(int i=0;i<n;i++){
            char top=st.top();
            if(s[i]==']'){

                if(top=='['){
                   st.pop();
                    
                }
                else{
                st.push('[');
                ans++;
                }

            }
            else{
                st.push('[');
            }
            
        }
        return ans;
    }
};