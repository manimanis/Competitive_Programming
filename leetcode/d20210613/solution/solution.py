from typing import List


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        pass


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'palindromePairs')