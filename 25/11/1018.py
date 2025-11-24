class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        ans = []
        num = 0
        for v in nums:
            num = ((num << 1) + v) % 5
            ans.append(num == 0)
        return ans