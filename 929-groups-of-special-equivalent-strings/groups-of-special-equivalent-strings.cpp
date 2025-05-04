class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> seen;

        for (string& word : A) {
            string even, odd;

            for (int i = 0; i < word.size(); i++) {
                if (i % 2 == 0) even += word[i];
                else odd += word[i];
            }

            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());

            seen.insert(even + "|" + odd);  
        }

        return seen.size();
    }
};



/* class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> seen;
        for(auto& word : A)
        {
            string codec(52,'a');
            for(int j=0;j<word.size();j++)
                codec[ word[j] - 'a' + 26*(j%2) ]++;
            seen.insert(codec);
        }
        return seen.size();
    }
}; */