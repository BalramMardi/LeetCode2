
class Solution {
    struct SegmentTree {
        int n;
        vector<int> cnt;
        vector<long long> len;
        vector<int> X;

        SegmentTree(const vector<int>& x_coords) {
            X = x_coords;
            n = X.size() - 1;
            cnt.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void update(int node, int start, int end, int l, int r, int val) {
            if (l >= end || r <= start) return;
            if (l <= start && end <= r) {
                cnt[node] += val;
            } else {
                int mid = (start + end) / 2;
                update(node * 2, start, mid, l, r, val);
                update(node * 2 + 1, mid, end, l, r, val);
            }
            pushup(node, start, end);
        }

        void pushup(int node, int start, int end) {
            if (cnt[node] > 0) {
                len[node] = (long long)X[end] - X[start];
            } else if (start + 1 == end) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }
    };

    struct Event {
        int y, type, x1, x2;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> X;
        for (auto& s : squares) {
            X.push_back(s[0]);
            X.push_back(s[0] + s[2]);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());

        auto getX = [&](int val) {
            return lower_bound(X.begin(), X.end(), val) - X.begin();
        };

        vector<Event> events;
        for (auto& s : squares) {
            int x1 = getX(s[0]);
            int x2 = getX(s[0] + s[2]);
            events.push_back({s[1], 1, x1, x2});
            events.push_back({s[1] + s[2], -1, x1, x2});
        }
        sort(events.begin(), events.end());

        SegmentTree st(X);
        long long total_area = 0;
        int prev_y = events[0].y;

        for (auto& e : events) {
            int curr_y = e.y;
            if (curr_y > prev_y) {
                total_area += st.len[1] * (long long)(curr_y - prev_y);
                prev_y = curr_y;
            }
            st.update(1, 0, st.n, e.x1, e.x2, e.type);
        }

        double target = total_area / 2.0;
        double curr_area = 0;
        
        SegmentTree st2(X);
        prev_y = events[0].y;

        for (auto& e : events) {
            int curr_y = e.y;
            if (curr_y > prev_y) {
                long long width = st2.len[1];
                double added = (double)width * (curr_y - prev_y);
                if (curr_area + added >= target) {
                    return prev_y + (target - curr_area) / width;
                }
                curr_area += added;
                prev_y = curr_y;
            }
            st2.update(1, 0, st2.n, e.x1, e.x2, e.type);
        }

        return 0.0;
    }
};