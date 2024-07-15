class Solution {
public:
    bool canFormSubsequence(const string &S1, const string &S2, const vector<int> &P, int t) {
        int N = S1.size();
        int M = S2.size();

        // Create a copy of S2 to simulate removals
        string Q = S2;
        
        // Mark the characters to be removed with a special character
        for (int i = 0; i < t; ++i) {
            Q[P[i]] = '.';
        }

        // Check if S1 is a subsequence of the modified S2 (Q)
        int j = 0;
        for (int i = 0; i < M && j < N; ++i) {
            if (Q[i] == S1[j]) {
                ++j;
            }
        }
        return j == N;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0, high = removable.size(), result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFormSubsequence(p, s, removable, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
