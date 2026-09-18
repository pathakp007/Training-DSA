class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();

        sort(points.begin(), points.end());

        int arrows = 1;

        int left = points[0][0];
        int right = points[0][1];

        for(int i = 1; i < n; i++) {

            int newLeft = max(left, points[i][0]);
            int newRight = min(right, points[i][1]);

            if(newLeft <= newRight) {

                left = newLeft;
                right = newRight;
            }

            else {

                arrows++;

                left = points[i][0];
                right = points[i][1];
            }
        }

        return arrows;
    }
};