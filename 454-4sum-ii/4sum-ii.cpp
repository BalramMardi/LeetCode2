class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> abSum;

        for (int a : A) {
            for (int b : B) {
                abSum[a + b]++;
            }
        }

        int count = 0;

        for (int c : C) {
            for (int d : D) {
                int target = -(c + d);
                if (abSum.find(target) != abSum.end()) {
                    count += abSum[target];
                }
            }
        }

        return count;
    }
};
