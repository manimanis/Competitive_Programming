from typing import List
import functools


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def dfs(l, r, bt):
            print(f"dfs({l}, {r}, \"{bt}\")")
            if l == 0:
                while r > 0:
                    bt = bt + ")"
                    r -= 1
                print(bt)
                res.append(bt)
                return

            if r == 0:
                return

            if r < l:
                return

            dfs(l-1, r, bt+"(")
            dfs(l, r-1, bt+")")

        dfs(n, n, "")
        return res


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'generateParenthesis',
                        prepare_out=lambda o: sorted(o),
                        prepare_res=lambda r: sorted(r))
