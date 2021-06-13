from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        def getAreaOfIsland(i: int, j: int, grid: List[List[int]]):
            if((i<0) or (i>=len(grid)) or (j<0) or (j>=len(grid[i])) ):
                return 0
            if(grid[i][j] == 1):
                grid[i][j]=0
                return 1 + (
                    getAreaOfIsland(i+1, j, grid)
                    + getAreaOfIsland(i-1, j, grid)
                    + getAreaOfIsland(i, j-1, grid) 
                    + getAreaOfIsland(i, j+1, grid) 
                )
            return 0
        
        max_val = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                max_val = max(max_val, getAreaOfIsland(i, j, grid))
        return max_val


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'maxAreaOfIsland')
