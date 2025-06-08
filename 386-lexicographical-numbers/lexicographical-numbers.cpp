#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<int, TrieNode*> children;
    bool isEnd = false;
};

class Solution {
    TrieNode* root;

    void insert(int num) {
        TrieNode* node = root;
        string s = to_string(num);
        for (char c : s) {
            int digit = c - '0';
            if (!node->children.count(digit))
                node->children[digit] = new TrieNode();
            node = node->children[digit];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, string current, vector<int>& result) {
        if (node->isEnd) {
            result.push_back(stoi(current));
        }
        for (int i = 0; i <= 9; ++i) {
            if (node->children.count(i)) {
                dfs(node->children[i], current + to_string(i), result);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        root = new TrieNode();
        for (int i = 1; i <= n; ++i) {
            insert(i);
        }

        vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            if (root->children.count(i)) {
                dfs(root->children[i], to_string(i), result);
            }
        }
        return result;
    }
};


/* class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> str;
        vector<int> ans;

        for(int i=1;i<=n;i++){
            string word = to_string(i);

            str.push_back(word);
        }

        sort(str.begin(),str.end());

        for(int i=0;i<str.size();i++){
            int num = stoi(str[i]);
            ans.push_back(num);
        }

        return ans;
    }
}; */