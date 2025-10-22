class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int idx = 0;
        int count = 0;
        int curr = 0;
        map<int, int> mp;
        vector<pair<int, int>> vec;

        for (int num : nums)
        {
            mp[num]++;
            vec.push_back({num - k, 1});
            vec.push_back({num + k + 1, -1});
        }

        set<int> st;
        for (auto &it : mp)
        {
            st.insert(it.first);
        }
        for (auto &it : vec)
        {
            st.insert(it.first);
        }

        sort(vec.begin(), vec.end());

        int maxifreq = 0;

        for (int it : st)
        {

            while (idx < vec.size() and vec[idx].first <= it)
            {
                curr += vec[idx].second;
                idx++;
            }

            if (mp.count(it))
            {
                count = mp[it];
            }
            else
            {
                count = 0;
            }

            int pfreq = count + min(numOperations, curr - count);

            maxifreq = max(maxifreq, pfreq);
        }

        return maxifreq;
    }
};