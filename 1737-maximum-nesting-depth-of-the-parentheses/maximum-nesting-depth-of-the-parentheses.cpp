class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxi=-1;
        for(int i=0;i<s.size();i++){

            if(s[i] == '('){
                st.push(i);

            }
            else if(s[i] == ')'){
                st.pop();
            
            }
            maxi=max(maxi,(int)st.size());
        }

        return maxi;
    }
};