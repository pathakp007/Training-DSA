class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        long long totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        long long leftSum = 0;
        long long minDiff = LLONG_MAX;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            leftSum += nums[i];

            long long rightSum = totalSum - leftSum;

            long long leftAvg = leftSum / (i + 1);

            long long rightAvg = 0;

            if (i != n - 1) {
                rightAvg = rightSum / (n - i - 1);
            }

            long long diff = abs(leftAvg - rightAvg);

            if (diff < minDiff) {
                minDiff = diff;
                ans = i;
            }
        }

        return ans;
    }
};