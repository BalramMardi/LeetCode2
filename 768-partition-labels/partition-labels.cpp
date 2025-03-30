class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            map<char, int> mp;

            for (int i = 0; i < s.length(); i++)
            {
                mp[s[i]] = i;
            }

            int prev = -1;
            int maxx = 0;
            vector<int> ans;
            for (int i = 0; i < s.length(); i++)
            {
                maxx = max(maxx, mp[s[i]]);
                if (maxx == i)
                {
                    ans.push_back(maxx - prev);
                    prev = maxx;
                }
            }

            return ans;
        }
};