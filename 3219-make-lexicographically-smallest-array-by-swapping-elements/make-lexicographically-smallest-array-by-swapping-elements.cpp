#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> numToGroup;
        vector<queue<int>> groupToQueue;

        int currGroup = 0;
        numToGroup[sortedNums[0]] = 0;
        groupToQueue.push_back(queue<int>());
        groupToQueue[0].push(sortedNums[0]);

        for (int i = 1; i < n; i++) {
            if (sortedNums[i] - sortedNums[i - 1] > limit) {
                currGroup++;
                groupToQueue.push_back(queue<int>());
            }
            numToGroup[sortedNums[i]] = currGroup;
            groupToQueue[currGroup].push(sortedNums[i]);
        }

        for (int i = 0; i < n; i++) {
            int group = numToGroup[nums[i]];
            nums[i] = groupToQueue[group].front();
            groupToQueue[group].pop();
        }

        return nums;
    }
};