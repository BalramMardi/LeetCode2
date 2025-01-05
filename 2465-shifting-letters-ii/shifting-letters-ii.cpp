class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (const auto &shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1)
            {
                diff[start] += 1;
                if (end + 1 < n)
                {
                    diff[end + 1] -= 1;
                }
            }
            else
            {
                diff[start] -= 1;
                if (end + 1 < n)
                {
                    diff[end + 1] += 1;
                }
            }
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i)
        {
            cumulativeShift += diff[i];

            int effectiveShift = cumulativeShift % 26;

            if (effectiveShift != 0)
            {
                char newChar = (s[i] - 'a' + effectiveShift + 26) % 26 + 'a';
                s[i] = newChar;
            }
        }

        return s;
    }
};