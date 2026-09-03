class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        int closetSum = 100000;

        sort(begin(nums), end(nums));

        for(int k = 0; k <= n-3; k++){
            int i = k + 1;
            int j = n - 1;

            while(i < j){
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(target - sum) < abs(target - closetSum) ){
                    closetSum = sum;
                }

                if(sum < target){
                    i++;
                }
                else{
                    j--;
                }
            }


        }
            return closetSum;

    
    }
};