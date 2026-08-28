#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Default sort compares points[i][0] first
        sort(points.begin(), points.end());

        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= end) {
                // Overlap exists: narrow down the arrow position
                end = min(end, points[i][1]);
            } else {
                // No overlap: shoot a new arrow
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};