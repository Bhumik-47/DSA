class Solution {
    int memo[21][21];

    int getNetScore(vector<int>& nums, int i, int j) {
        if (i == j) return nums[i];
        if (memo[i][j] != -1) return memo[i][j];

        // Pick left element OR pick right element
        int pickLeft  = nums[i] - getNetScore(nums, i + 1, j);
        int pickRight = nums[j] - getNetScore(nums, i, j - 1);

        return memo[i][j] = max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return getNetScore(nums, 0, nums.size() - 1) >= 0;
    }
};