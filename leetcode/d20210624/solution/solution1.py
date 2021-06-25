from typing import List


class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        if maxMove == 0:
            return 0
        
        NUM = 1_000_000_007
        
        prev = [[0]*n for _ in range(m)]
        
        for k in range(maxMove):
            curr = [[0]*n for _ in range(m)]
            for row in range(m):
                for col in range(n):
                    curr[row][col] = (curr[row][col] + (1 if row == 0 else prev[row-1][col])) % NUM
                    curr[row][col] = (curr[row][col] + (1 if row == (m-1) else prev[row+1][col])) % NUM
                    curr[row][col] = (curr[row][col] + (1 if col == 0 else prev[row][col-1])) % NUM
                    curr[row][col] = (curr[row][col] + (1 if col == (n-1) else prev[row][col+1])) % NUM
            prev = curr
        
        return prev[startRow][startColumn] % NUM


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'findPaths')
