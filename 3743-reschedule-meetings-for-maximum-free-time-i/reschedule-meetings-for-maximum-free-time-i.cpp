class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        vector<int> free;

        free.push_back(startTime[0]);
        for(int i = 1; i < n; i++){
            free.push_back(startTime[i] - endTime[i-1]);
        }
        free.push_back(eventTime - endTime[endTime.size()-1]);



        for(auto it : free){
            cout << it << " ";
        }

        int left=0;
        int right=0;
        int sum=0;
        int maxi=0;
        while(right < free.size()){

            sum += free[right];

            if(left < free.size() && right-left+1 > k+1){
                sum -= free[left];
                left++;
            }

            maxi = max(maxi,sum);

            right++;
        }

        return maxi;
    }
};


/* class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + endTime[i] - startTime[i];
        }
        for (int i = k - 1; i < n; i++) {
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            int left = i == k - 1 ? 0 : endTime[i - k];
            res = max(res, right - left - (sum[i + 1] - sum[i - k + 1]));
        }
        return res;
    }
}; */