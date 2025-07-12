class Solution {
public:
    int mn = INT_MAX;
    int mx = INT_MIN;
    int first, second;

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> arr(n);
        for(int i = 1; i <= n; i++) arr[i - 1] = i;
        first = firstPlayer;
        second = secondPlayer;
        dfs(arr, 1);
        return {mn, mx};
    }

private:
    void dfs(vector<int>& arr, int round) {
        int n = arr.size();
        int size = n / 2;
        if(arr.size() == 1) return;

        for(int i = 0; i < size; i++) {
            if(arr[i] == first && arr[n - i - 1] == second) {
                mn = min(mn, round);
                mx = max(mx, round);
                return;
            }
        }

        bool f1 = false, f2 = false;
        for (int i = 0; i < n; i++) {
            if(arr[i] == first) f1 = true;
            if(arr[i] == second) f2 = true;
        }

        if (!f1 || !f2) return;

        vector<int> nextarr(size + (n % 2));
        int m = (1 << size) - 1;

        for(int i = 0; i <= m; i++){
            int left = 0, right = nextarr.size() - 1;

            for (int j = 0; j < size; j++) {
                if((1 << j) & i) {
                    nextarr[left++] = arr[j];
                } else {
                    nextarr[right--] = arr[n - j - 1];
                }
            }

            if (arr.size() % 2) {
                nextarr[left] = arr[arr.size() / 2];
            }

            dfs(nextarr, round + 1);
        }
    }
};
