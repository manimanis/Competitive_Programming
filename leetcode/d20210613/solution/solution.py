from typing import List


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        def isPalindrome(s):
            i, j = 0, len(s)-1
            while j > i and s[i] == s[j]:
                i, j = i+1, j-1
            return i >= j

        res = []
        n = len(words)
        for i in range(n):
            for j in range(i+1, n):
                w = words[i] + words[j]
                w1 = words[j] + words[i]
                if isPalindrome(w):
                    res.append([i, j])
                    if w1 == w:
                        res.append([j, i])
                        continue
                if isPalindrome(w1):
                    res.append([j, i])
        return res


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'palindromePairs')