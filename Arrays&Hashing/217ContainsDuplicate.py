class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        m = {}
        for index,num in enumerate(nums):
            if num in m :
                return True
            else:
                m[num] = index
        return False
       