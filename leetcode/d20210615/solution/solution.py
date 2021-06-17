from typing import List


class Solution:
    def makesquare(self, ms: List[int]) -> bool:
        def solve(ms, square, pos, side):
            print(f"solve({ms}, {square}, {pos}, {side})")
            if pos >= len(ms):
                return all(ss == side for ss in square)
            
            for i in range(4):
                if ms[pos] + square[i] <= side:
                    square[i] += ms[pos]
                    if solve(ms, square, pos+1, side):
                        return True
                    else:
                        square[i] -= ms[pos]

            return False

        perimeter = sum(ms)
        if perimeter % 4 != 0:
            return False
        side = perimeter // 4
        ms.sort(reverse=True)
        return solve(ms, [0]*4, 0, side)


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'makesquare')
