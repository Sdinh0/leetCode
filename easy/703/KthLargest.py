import heapq
from typing import List

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.kLargest = []
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        if len(self.kLargest) < self.k:
            heapq.heappush(self.kLargest, val)
        elif self.kLargest[0] < val:
            heapq.heapreplace(self.kLargest, val)
        return self.kLargest[0]