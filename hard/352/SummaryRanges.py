from typing import List

class SummaryRanges:

    def __init__(self):
        self.intervals = []
        
    def addNum(self, value: int) -> None:
        left = None
        right = None

        for interval in self.intervals:
            if interval[0] <= value <= interval[1]:
                return
            if interval[0] == value+1:
                left = interval
            if interval[1] == value-1:
                right = interval

        if left and right:
            self.intervals.remove(left)
            self.intervals.remove(right)
            self.intervals.append([min(left[0], right[0]), max(left[1], right[1])])
        elif left:
            left[0] = value
        elif right:
            right[1] = value
        else:
            self.intervals.append([value, value])

        self.intervals.sort(key=lambda interval: interval[0])

    def getIntervals(self) -> List[List[int]]:
        return self.intervals