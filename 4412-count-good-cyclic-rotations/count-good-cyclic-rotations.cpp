#include <vector>

class Solution {
public:
    int countGoodRotations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int half1 = n / 2;

        long long sum1 = 0;
        for (int i = 0; i < half1; ++i) {
            sum1 += nums[i];
        }

        long long sum2 = 0;
        for (int i = half1; i < n; ++i) {
            sum2 += nums[i];
        }

        int good_rotations = 0;

        for (int k = 0; k < n; ++k) {
            if (sum1 > sum2) {
                good_rotations++;
            }

            // Slide windows forward using modulo indexing
            sum1 -= nums[k];
            sum1 += nums[(k + half1) % n];

            sum2 -= nums[(k + half1) % n];
            sum2 += nums[k]; // (k + n) % n == k
        }

        return good_rotations;
    }
};