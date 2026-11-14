class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsa = INT_MAX;
        
        // Check every possible starting point
        for (int i = 0; i < n; i++) {
            int current_sum = 0;
            
            // Expand the subarray from the starting point
            for (int j = i; j < n; j++) {
                current_sum += nums[j];
                int length = j - i + 1;
                
                // If length exceeds r, no need to keep going from this starting point
                if (length > r) break;
                
                // If length is within bounds and sum is positive, update minimum
                if (length >= l && length <= r && current_sum > 0) {
                    minsa = min(minsa, current_sum);
                }
            }
        }
        
        return (minsa == INT_MAX) ? -1 : minsa;
    }
};