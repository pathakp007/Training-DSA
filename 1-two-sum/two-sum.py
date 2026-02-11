class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m={}
        for i,j in enumerate(nums):
            res = target-j
            if res in m:
                return[m[res],i]
            m[j]=i