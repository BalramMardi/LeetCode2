class Solution {
public:
    string addOperation(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        int n = s.size();
        rotate(s.begin(), s.begin() + (n - b), s.end());
        return s;
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string smallest = s;
        
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            smallest = min(smallest, curr);

            string addStr = addOperation(curr, a);
            if (!visited.count(addStr)) {
                visited.insert(addStr);
                q.push(addStr);
            }

            string rotStr = rotateOperation(curr, b);
            if (!visited.count(rotStr)) {
                visited.insert(rotStr);
                q.push(rotStr);
            }
        }
        return smallest;
    }
};
