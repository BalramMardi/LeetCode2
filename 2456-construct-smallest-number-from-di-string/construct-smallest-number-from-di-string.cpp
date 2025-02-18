class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string res = "";
        int counter=1;
        for(int i=0;i<=pattern.size();i++){

            st.push(counter+'0');
            counter++;

            if(i == pattern.size() || pattern[i]=='I'){
                while(st.size()){
                    res += st.top();
                    st.pop();
                }
            }

            
        }

        return res;
    }
};