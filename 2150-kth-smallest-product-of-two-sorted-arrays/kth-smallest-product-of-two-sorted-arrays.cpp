class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            for (int num : nums1) {
                if (num == 0) {
                    if (mid >= 0) {
                        count += nums2.size();
                    }
                } else if (num > 0) {
                    long long target = mid / num;
                    if (mid % num != 0 && mid < 0) {
                        target--;
                    }
                    auto it = upper_bound(nums2.begin(), nums2.end(), target);
                    count += it - nums2.begin();
                } else {
                    long long target = mid / num;
                    if (mid % num != 0 && mid < 0) {
                        target++;
                    }
                    auto it = lower_bound(nums2.begin(), nums2.end(), target);
                    count += nums2.end() - it;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};