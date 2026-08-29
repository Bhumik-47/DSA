#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSplits(const vector<int>& v) {
        int m = v.size();
        if (m < 2) return 0;

        vector<int> pref(m), suff(m);
        pref[0] = v[0];
        for (int i = 1; i < m; ++i) {
            pref[i] = std::gcd(pref[i - 1], v[i]);
        }

        suff[m - 1] = v[m - 1];
        for (int i = m - 2; i >= 0; --i) {
            suff[i] = std::gcd(suff[i + 1], v[i]);
        }

        int validSplits = 0;
        // Split between t and t + 1
        for (int t = 0; t < m - 1; ++t) {
            if (pref[t] == suff[t + 1]) {
                validSplits++;
            }
        }
        return validSplits;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        // Base case: 0 removals
        int maxSplits = countSplits(nums);

        // Try removing each element i
        for (int i = 0; i < n; ++i) {
            vector<int> v;
            v.reserve(n - 1);
            for (int j = 0; j < n; ++j) {
                if (j != i) v.push_back(nums[j]);
            }
            maxSplits = max(maxSplits, countSplits(v));
        }

        return maxSplits;
    }
};