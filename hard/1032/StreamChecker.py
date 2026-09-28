from typing import List

class StreamChecker:

    def __init__(self, words: List[str]):
        self.words = set(words)
        self.maxLen = max(map(len, words))
        self.stream = ""

    def query(self, letter: str) -> bool:
        self.stream += letter

        if len(self.stream) > self.maxLen:
            self.stream = self.stream[-self.maxLen:]

        return any(self.stream.endswith(word) for word in self.words)
     