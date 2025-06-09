class Solution {
public:
    long long countPrefix(long long prefix, long long n) {
        long long count = 0, cur = prefix, next = prefix + 1;
        while (cur <= n) {
            count += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1;

        while (k > 0) {
            long long steps = countPrefix(curr, n);
            if (steps <= k) {
                curr += 1;     // move to next sibling
                k -= steps;
            } else {
                curr *= 10;    // move to first child
                k -= 1;
            }
        }

        return curr;
    }
};


/* class Trie {
public:
    unordered_map<int, Trie*> children;
    bool isEnd = false;
};

class Solution {
public:
    Trie* root = new Trie();

    void insert(int val) {
        Trie* node = root;
        string s = to_string(val);
        for (char c : s) {
            int digit = c - '0';
            if (!node->children.count(digit)) {
                node->children[digit] = new Trie();
            }
            node = node->children[digit];
        }
        node->isEnd = true;
    }

    void dfs(Trie* node, string curr, int& k, int& ans) {
        if (k == 0) return;

        if (node->isEnd) {
            k--;
            if (k == 0) {
                ans = stoi(curr);
                return;
            }
        }

        for (int i = 0; i <= 9; ++i) {
            if (node->children.count(i)) {
                dfs(node->children[i], curr + char('0' + i), k, ans);
                if (k == 0) return;
            }
        }
    }

    int findKthNumber(int n, int k) {
        for (int i = 1; i <= n; ++i) {
            insert(i);
        }

        int ans = -1;
        for (int i = 1; i <= 9; ++i) {
            if (root->children.count(i)) {
                dfs(root->children[i], to_string(i), k, ans);
                if (k == 0) break;
            }
        }
        return ans;
    }
};
 */