class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for index,num in enumerate(nums):
            d = target-num
            if d in m:
                return [m[d],index]
            m[num] = index