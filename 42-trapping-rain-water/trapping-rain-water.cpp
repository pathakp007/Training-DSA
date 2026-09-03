class Solution {
public:

    vector<int> getleftMaxArray(vector<int>&height, int&n){
        vector<int> leftMax(n);

        leftMax[0] = height[0];

        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    vector<int> getRightMaxArray(vector<int>& height, int& n){
        vector<int> RightMax(n);

        RightMax[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--){
            RightMax[i] = max(RightMax[i + 1], height[i]);
        }
        return RightMax;
    }


    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax = getleftMaxArray(height, n);
        vector<int> RightMax = getRightMaxArray(height, n);

        int sum = 0;

        for(int i = 0; i < n; i++){
            int h = min(leftMax[i], RightMax[i]) - height[i];
             
            sum += h;
        }

        return sum;
    }
};