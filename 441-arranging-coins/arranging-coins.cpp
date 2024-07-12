class Solution {
public:
    int arrangeCoins(int n) {
       long left = 0, right = n, mid, current_sum;
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        current_sum = mid * (mid + 1) / 2;
        
        if (current_sum == n) {
            return mid; 
        } else if (current_sum < n) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    
    return right; 
    }
};