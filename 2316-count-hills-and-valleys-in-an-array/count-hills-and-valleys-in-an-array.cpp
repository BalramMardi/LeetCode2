class Solution {
public:
    bool isValid(vector<int>& group) {
        int a = group[0];
        int b = group[1];
        int c = group[2];
        return (a < b && b > c) || (a > b && b < c);
    }

    int countHillValley(vector<int>& nums) {
        vector<int> triplet;
        int result = 0;

        for (int num : nums) {
            if (triplet.empty() || triplet.back() != num) {
                if (triplet.size() < 3) {
                    triplet.push_back(num);
                } else {
                    result += (int)isValid(triplet);
                    triplet[0] = triplet[1];
                    triplet[1] = triplet[2];
                    triplet[2] = num;
                }
            }
        }

        if (triplet.size() == 3) {
            result += (int)isValid(triplet);
        }

        return result;
    }
};