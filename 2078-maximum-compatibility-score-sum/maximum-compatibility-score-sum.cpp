class Solution {
public:
    int maxScore = 0;

    int getScore(vector<int>& student, vector<int>& mentor) {
        int score = 0;
        for (int i = 0; i < student.size(); i++) {
            if (student[i] == mentor[i]) score++;
        }
        return score;
    }

    void backtrack(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool>& visited, int index, int currScore) {
        if (index >= students.size()) {
            maxScore = max(maxScore, currScore);
            return;
        }

        for (int i = 0; i < mentors.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                backtrack(students, mentors, visited, index + 1, currScore + getScore(students[index], mentors[i]));
                visited[i] = false;
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> visited(m, false);
        backtrack(students, mentors, visited, 0, 0);
        return maxScore;
    }
};
