class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = {}
        res = []
        values = [[] for i in range(len(nums)+1)]
        
        for num in nums:
            if num in m:
                m[num] = m[num] + 1
            else :
                m[num] = 1

        
        for n,c in m.items():
            values[c].append(n)

        for i in range(len(values)-1,0,-1):
            for val in values[i]:
                res.append(val)
                if len(res)==k :
                    return res
                
        

        