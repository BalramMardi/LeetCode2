class Solution {
public:
    int partitionString(string str) {
          vector<int> freq(26, 0);
        int counter = 1;
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            if (freq[ch - 'a'] == 1)
            {
                counter++;
                freq.assign(26, 0);
            }
            freq[ch - 'a']++;
        }
        return counter;
    }
};


/* class Solution {
public:
    int partitionString(string s) {
          vector<int>ans(26,0) ;
          int count  = 1;
        //   ans[]
          for(int i = 0 ; i < s.size() ; i ++ ){              
            ans[s[i]- 'a'] ++; 
            if(ans[s[i]- 'a' ] ==2 ){
                count ++ ; 
                fill(ans.begin() , ans.end() , 0) ;
                ans[s[i] - 'a']++;
                continue ;
            }
          }
          return count ;
    }
}; */