class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            size_t part_start_index = s.find(part);
            s = s.substr(0, part_start_index) +
                s.substr(part_start_index + part.length());
        }
        return s;
    }
};