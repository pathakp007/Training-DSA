class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); // rows
        int n = matrix[0].size(); // column

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        int d = 0;
        vector<int> result;

        while(left <= right && top <= bottom) {

            if(d == 0) {
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }

            if(d == 1) {
                for(int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            if(d == 2) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(d == 3) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            d++;

            if(d == 4) {
                d = 0;
            }
        }

        return result;
    }
};