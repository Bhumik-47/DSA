class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Step 1: Find the peak index
        int st = 0, en = n - 1;
        while (st < en) {
            int mid = st + (en - st) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                st = mid + 1;
            } else {
                en = mid;
            }
        }
        int peak = st;

        // Step 2: Binary search on the strictly increasing left side [0, peak]
        st = 0;
        en = peak;
        while (st <= en) {
            int mid = st + (en - st) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid; // Return immediately (smallest index guaranteed)
            } else if (val < target) {
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        // Step 3: Binary search on the strictly decreasing right side [peak + 1, n - 1]
        st = peak + 1;
        en = n - 1;
        while (st <= en) {
            int mid = st + (en - st) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                // Notice the reversed condition because the array is decreasing
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        return -1;
    }
};