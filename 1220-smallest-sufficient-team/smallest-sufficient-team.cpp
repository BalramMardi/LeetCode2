class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int m = people.size();

        // Map each skill to an index
        unordered_map<string, int> skill_index;
        for (int i = 0; i < n; ++i)
        {
            skill_index[req_skills[i]] = i;
        }

        // Convert each person's skills into a bitmask
        vector<int> person_skill(m, 0);
        for (int i = 0; i < m; ++i)
        {
            for (const string &skill : people[i])
            {
                if (skill_index.count(skill))
                {
                    person_skill[i] |= (1 << skill_index[skill]);
                }
            }
        }

        // DP table to store the smallest team for each skill combination
        unordered_map<int, vector<int>> dp;
        dp[0] = {}; // Base case: no skills require an empty team

        for (int i = 0; i < m; ++i)
        {
            auto current_dp = dp; // Copy the current state of dp to iterate over
            for (const auto &[skill_mask, team] : current_dp)
            {
                int new_mask = skill_mask | person_skill[i]; // Add current person's skills
                if (dp.find(new_mask) == dp.end() || dp[new_mask].size() > team.size() + 1)
                {
                    dp[new_mask] = team;
                    dp[new_mask].push_back(i); // Add this person to the team
                }
            }
        }

        // The smallest team for the mask covering all skills
        return dp[(1 << n) - 1];
    }
};