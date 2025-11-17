
def kLengthApart(self, nums: List[int], k: int) -> bool:
    last = -k-1
    for i ,x in enumerate(nums):
        if x != 1:
            continue
        if i - last <= k:
            return False
        last = i
    return True