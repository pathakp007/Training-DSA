class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        mv = nums[0]
        minv = nums[0]
        ans = nums[0]

        for i in range(1, len(nums)):
            v = nums[i]

            prev_mv = mv
            prev_minv = minv

            mv = max(v, v * prev_mv, v * prev_minv)
            minv = min(v, v * prev_mv, v * prev_minv)

            ans = max(ans, mv)

        return ans