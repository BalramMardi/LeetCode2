class Solution {
public:
    pair<int, int> solve(const vector<int>& candles, int left, int right) {
        int leftCandle = -1;
        auto itLeft = lower_bound(candles.begin(), candles.end(), left);
        if (itLeft != candles.end() && *itLeft <= right) {
            leftCandle = *itLeft;
        }

        int rightCandle = -1;
        auto itRight = upper_bound(candles.begin(), candles.end(), right);
        if (itRight != candles.begin()) {
            rightCandle = *(--itRight);
        }

        return {leftCandle, rightCandle};
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.size();
        vector<int> prefix(len, 0);
        vector<int> candles;

        prefix[0] = (s[0] == '*' ? 1 : 0);
        if (s[0] == '|') candles.push_back(0);

        for (int i = 1; i < len; i++) {
            prefix[i] = prefix[i - 1] + (s[i] == '*' ? 1 : 0);
            if (s[i] == '|') candles.push_back(i);
        }

        vector<int> ans(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            auto candlesPos = solve(candles, start, end);
            int leftCandle = candlesPos.first;
            int rightCandle = candlesPos.second;

            if (leftCandle == -1 || rightCandle == -1 || leftCandle >= rightCandle) {
                ans[i] = 0;
            } else {
                ans[i] = prefix[rightCandle] - prefix[leftCandle];
            }
        }

        return ans;
    }
};



/* class Solution {
public:
    pair<int, int> solve(string &s, int left, int right) {
        int leftCandle = -1, rightCandle = -1;

        while (left < s.size() && left <= right) { 
            if (s[left] == '|') {
                leftCandle = left;
                break;
            }
            left++;  
        }

        while (right >= 0 && right >= left) { 
            if (s[right] == '|') {
                rightCandle = right;
                break;
            }
            right--;  
        }

        return {leftCandle, rightCandle};
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int len = s.size();
        vector<int> prefix(len, 0);
        prefix[0] = (s[0] == '*' ? 1 : 0);

        for (int i = 1; i < len; i++) {
            int star = (s[i] == '*' ? 1 : 0);
            prefix[i] = prefix[i - 1] + star;
        }

        vector<int> ans(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            auto candles = solve(s, start, end);  

            int leftCandle = candles.first;
            int rightCandle = candles.second;

            if (leftCandle == -1 || rightCandle == -1 || leftCandle >= rightCandle) {
                ans[i] = 0; 
            } else if (leftCandle > 0) {
                ans[i] = prefix[rightCandle] - prefix[leftCandle - 1];
            } else {
                ans[i] = prefix[rightCandle];
            }
        }

        return ans;
    }
}; */



