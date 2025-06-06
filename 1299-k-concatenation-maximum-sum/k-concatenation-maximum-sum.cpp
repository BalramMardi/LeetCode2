class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        if(k==1){
            ll singleKadane = kadane(arr);
            return singleKadane % MOD;
        }

        //double wala
        vector<int> doubleArr = arr;

        doubleArr.insert(doubleArr.begin(),arr.begin(),arr.end());

        ll doubleKadane = kadane(doubleArr);


        ll totalSum = accumulate(arr.begin(),arr.end(),0LL);

        
        if(totalSum > 0){
            return ((k-2)*totalSum + doubleKadane) % MOD;
        }
        else{
            return doubleKadane % MOD;
        }
    }

    ll kadane(vector<int> & arr){

        ll maxCurr=0;
        ll maxOver=0;
        for(auto num : arr){

            maxCurr = max((ll)num, num+maxCurr);
            maxOver = max(maxCurr, maxOver);
        }

        return maxOver;
    }
};



/* class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        long long presum = 0, premax = 0;
        long long sufsum = 0, sufmax = 0;
        long long cursum = 0, curmax = 0;
        long long total = 0;

        for (int i = 0; i < n; ++i) {
            presum += arr[i];
            premax = max(premax, presum);

            sufsum += arr[n - 1 - i];
            sufmax = max(sufmax, sufsum);

            cursum = max(0LL, cursum) + arr[i];
            curmax = max(curmax, cursum);

            total += arr[i];
        }

        long long maxSum;
        if (k == 1) {
            maxSum = curmax;
        } else {
            maxSum = max(curmax, premax + sufmax + max(0LL, total) * (k - 2));
        }

        return (int)(maxSum % mod);
    }
};
 */