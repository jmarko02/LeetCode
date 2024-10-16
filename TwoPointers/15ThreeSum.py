class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums = sorted(nums)
        for i in range(len(nums)):

            if i > 0 and nums[i]==nums[i-1]:
                continue    
            l = i + 1
            r = len(nums)-1
            while l<r: 
                treeSum = nums[i] +nums[l]+nums[r]
                if treeSum > 0 :
                    r -= 1
                    #while nums[r]==nums[r+1] and l < r:
                    #   r -= 1 
                elif treeSum < 0 :
                    l += 1
                    #while nums[l]==nums[l-1] and l < r:
                    #    l += 1
                else :
                    res.append([nums[i],nums[l],nums[r]])
                    l += 1
                    while nums[l]==nums[l-1] and l < r:
                        l += 1

        return res