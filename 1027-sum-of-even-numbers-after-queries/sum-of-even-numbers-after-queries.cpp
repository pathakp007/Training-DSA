class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        int SumEven = 0;

        for(int &x : nums ){
            if(x % 2 == 0){
                SumEven += x;
            }
        }
        vector<int> result;

        for(int i = 0; i < q; i++){
        int val = queries[i][0];
        int idx = queries[i][1];

        if(nums[idx] % 2 == 0){
            SumEven -= nums[idx];
                }

        nums[idx] += val;

        if(nums[idx] % 2 == 0){
            SumEven += nums[idx];
                }

        result.push_back(SumEven);            
        }

        return result;
        
    }
};