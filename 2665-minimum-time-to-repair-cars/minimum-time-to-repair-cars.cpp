class Solution {
public:
    typedef long long ll;

    bool possible(ll mid, vector<int> &ranks, int cars) {
        ll sum = 0;
        for (int i = 0; i < ranks.size(); i++) {
            sum += (ll)sqrt(mid / (double)ranks[i]);  
            if (sum >= cars) return true; 
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 0, high = (ll)(*min_element(ranks.begin(), ranks.end())) * (ll)cars * cars; 
        ll ans = 0;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (possible(mid, ranks, cars)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
