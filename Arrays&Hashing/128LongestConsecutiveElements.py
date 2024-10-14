class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        numSet = set(nums)
        max_length = 0

        for num in numSet:
            if (num-1) not in numSet:
                curr_length = 0
                while (num + curr_length) in numSet:
                    curr_length += 1
                max_length = max(max_length, curr_length)
        return max_length