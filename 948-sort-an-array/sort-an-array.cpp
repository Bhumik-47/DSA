class Solution {
private:
    void mergesort(vector<int>& nums, vector<int>& temp, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergesort(nums, temp, l, mid);
        mergesort(nums, temp, mid + 1, r);

        // Merge step using pre-allocated buffer
        int s1 = l, s2 = mid + 1;
        int idx = l;

        while (s1 <= mid && s2 <= r) {
            if (nums[s1] <= nums[s2]) {
                temp[idx++] = nums[s1++];
            } else {
                temp[idx++] = nums[s2++];
            }
        }

        while (s1 <= mid) {
            temp[idx++] = nums[s1++];
        }

        while (s2 <= r) {
            temp[idx++] = nums[s2++];
        }

        // Copy merged elements back to original array
        for (int i = l; i <= r; ++i) {
            nums[i] = temp[i];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        
        vector<int> temp(nums.size());
        mergesort(nums, temp, 0, (int)nums.size() - 1);
        return nums;
    }
};