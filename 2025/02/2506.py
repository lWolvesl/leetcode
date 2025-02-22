from collections import Counter
from typing import List

class Solution:
    def similarPairs(self, words: List[str]) -> int:
        res = 0
        cnt = Counter()
        for word in words:
            state = 0
            for c in word:
                state |= 1 << (ord(c) - ord('a'))
            res += cnt[state]
            cnt[state] += 1
        return res