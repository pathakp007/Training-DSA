class Solution {
public:
    
    int binarySearch(vector<int>& nums, int n, int target) {
        int l = 0, r = n-1;
        int mid;
        int result_idx = -1;
        
        while(l <= r) {
            mid = l + (r-l)/2;
            if(nums[mid] <= target) {
                result_idx = mid;
                l = mid+1;
            } else if(nums[mid] > target) {
                r = mid-1;
            }
        }
        return result_idx+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        
        int m = queries.size();
        vector<int> result(m);
        
        for(int i = 0; i<m; i++) {
            auto it = binarySearch(nums, n, queries[i]);
            
            result[i] = it;
        }
        return result;
    }
};
